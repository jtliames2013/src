RateLimit，允许每个IP在每秒内CALL100次，超过100次返回false。没有研究过uber的面经，这道题可能是高频题吧？

Develop an API Rate-limit Throttling Client.
要求写一个api， 请求第三方api， 如果一秒内的请求太多， 自己的api就直接忽略掉。

设计call rate limit.具体是说给你一个ip，你先chec是否有大于100个call from this ip since last second. 大于100就throw exception，没有的话就 do sth。


#include <chrono>
#include <ctime>
#include <thread>

using namespace std;
using namespace std::chrono;

class Bucket {
public:
	Bucket() {}

	Bucket(long r, long c) {
		rate=r;
		capacity=c;
		tokens=c;
		lasttime=system_clock::now();
	}

	bool tryAccept() {
		lock_guard<mutex> guard(mx);
		auto currtime=system_clock::now();
		duration<double> diff = currtime-lasttime;
		tokens=min(capacity, tokens+long(diff.count()*rate));
		lasttime=currtime;

		if (tokens<=0) {
			return false;
		} else {
			tokens--;
			return true;
		}
	}

	duration<double> take(long count) {
		lock_guard<mutex> guard(mx);
		if (count<=0) return duration<double>(0);

		auto currtime=system_clock::now();
		duration<double> diff = currtime-lasttime;
		tokens=min(capacity, tokens+long(diff.count()*rate));
		lasttime=currtime;

		tokens-=count;
		if (tokens>=0) {
			return duration<double>(0);
		}

		double t=double(-tokens)/rate;

		return duration<double>(t);
	}

	void accept() {
		duration<double> d=take(1);
		this_thread::sleep_for(d);
	}

	time_point<system_clock> lasttime;
	long capacity;
	long rate;
	long tokens;
	mutex mx;
};

class Client {
public:
	Client() {}

	bool tryAccept(string ip) {
		{
			lock_guard<mutex> guard(mx);
			if (mp.find(ip)==mp.end()) {
				mp[ip]=new Bucket(rate, capacity);
			}
		}

		if (mp[ip]->tryAccept()==false) return false;

		return true;
	}

	void accept(string ip) {
		{
			lock_guard<mutex> guard(mx);
			if (mp.find(ip)==mp.end()) {
				mp[ip]=new Bucket(rate, capacity);
			}
		}

		mp[ip]->accept();
	}

	unordered_map<string, Bucket*> mp;
	mutex mx;
	const long rate=100;
	const long capacity=100;
};

int main() {
	Client client;

	for (int i=0; i<150; i++) {
		bool b=client.tryAccept("10.204.0.1");
		cout << "i=" << i << " " << b << endl;
	}

	auto start=system_clock::now();
	for (int i=0; i<150; i++) {
		client.accept("10.204.0.2");
		auto end=system_clock::now();
		duration<double> diff = end-start;
		cout << "i=" << i << " " << diff.count() << endl;
	}

	return 0;
}

