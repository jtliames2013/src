class Crawler {
public:
	Crawler(int cap, string url) {
		this->capacity=cap;
		this->waiting=0;
		q.push(url);
		visited.insert(url);
	}

	void crawl() {
		while (1) {
			string f;
			{
				unique_lock<mutex> lock(mx);
				while (q.empty()) {
					waiting++;
					if (waiting==capacity) {
						cv.notify_one()();
						return;
					}
					cv.wait(lock, [this](){ return !q.empty(); });
					waiting--;
				}
				f=q.front();
				q.pop();
			}

			vector<string> urls=getLinks(f);

			{
				unique_lock<mutex> lock(mx);
				for (auto& u:urls) {
					if (visited.find(u)==visited.end()) {
						q.push(u);
						visited.insert(u);
					}
				}

				if (!q.empty()) cv.notify_all();
			}
		}
	}

	vector<string> getLinks(string url) {
		return vector<string>();
	}
private:
	mutex mx;
	condition_variable cv;
	int capacity;
	int waiting;
	unordered_set<string> visited;
	queue<string> q;
};

void dowork(Crawler &crawler) {
	crawler.crawl();
}

int main() {
	const int num=10;
	string url="foo";
	Crawler crawler(num, url);
	thread *threads[num];
	for (int i=0; i<num; i++) {
		threads[i]=new thread(dowork, std::ref(crawler));
	}

	for (int i=0; i<num; i++) {
		threads[i]->join();
	}

	for (int i=0; i<num; i++) {
		delete threads[i];
	}

	return 0;
}

