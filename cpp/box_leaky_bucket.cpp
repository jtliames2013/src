#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <functional>
#include <exception>
#include <stdexcept>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;


class LeakyBucket {
public:
	LeakyBucket():bufSize(10), rate(100000) {
		worker=thread(&LeakyBucket::consume, this);
	}

	~LeakyBucket() {
	}

	void join() {
		bufCv.notify_all();
		worker.join();
		cout << "after thread join..." << endl;
	}

	int produce(int val) {
		bufMutex.lock();
		if (buf.size()==bufSize) {
			cout << "drop " << val << " due to full!" << endl;
			bufMutex.unlock();
			return 0;
		}

		buf.push_back(val);
		cout << "fill " << val << " successful..." << endl;
		bufCv.notify_all();
		bufMutex.unlock();
		return 0;
	}

	void consume() {
		while (1) {
			std::unique_lock<std::mutex> lk(bufMutex);
			if (buf.empty()) {
				bufCv.wait(lk);
			}

			if (buf.empty()) return;
			cout << "consume " << buf.front() << endl;
			buf.pop_front();

			usleep(rate);
		}
	}
private:
	const size_t bufSize;
	const int rate;
	deque<int> buf;
	mutex bufMutex;
	condition_variable bufCv;
	thread worker;
};

int main()
{
	LeakyBucket bucket;
	srand (time(NULL));

	for (int i=0; i<20; i++) {
		bucket.produce(i);
		float t=rand()%10;
		usleep(t);
	}

	sleep(3);
	bucket.join();
	return 0;
}

