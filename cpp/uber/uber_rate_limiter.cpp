RateLimit，允许每个IP在每秒内CALL100次，超过100次返回false。没有研究过uber的面经，这道题可能是高频题吧？

Develop an API Rate-limit Throttling Client.
要求写一个api， 请求第三方api， 如果一秒内的请求太多， 自己的api就直接忽略掉。

设计call rate limit.具体是说给你一个ip，你先chec是否有大于100个call from this ip since last second. 大于100就throw exception，没有的话就 do sth。

1. token bucket
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

		if (tokens>0) {
			tokens--;
			lasttime=currtime;
			return true;
		}
		return false;
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
		lasttime+=duration<double>(t);
		return duration<double>(t);
	}

	void accept() {
		duration<double> d=take(1);
		this_thread::sleep_for(d);
	}

	time_point<system_clock, duration<double>> lasttime;
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

	for (int i=0; i<100; i++) {
		bool b=client.tryAccept("10.204.0.1");
		cout << "i=" << i << " " << b << endl;
	}
	for (int i=100; i<150; i++) {
		this_thread::sleep_for(duration<double>(0.005));
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

2. Hit count
class HitCount {
public:
	HitCount() {
		hits=0;
	}

	bool tryAccept(time_point<system_clock> timestamp) {
		removeHits(timestamp);
		if (hits>=capacity) return false;
		if (!q.empty() && q.back().first==timestamp) q.back().second++;
		else q.push({timestamp, 1});
		hits++;
		return true;
	}

private:
	void removeHits(time_point<system_clock> timestamp) {
		while (!q.empty() && duration<double>(timestamp-q.front().first).count()>=span) {
			hits-=q.front().second;
			q.pop();
		}
	}

	queue<pair<time_point<system_clock>,int>> q;
	int hits;
	const int capacity=100;
	const int span=1;
};

class Client {
public:
	Client() {}

	bool tryAccept(string ip) {
		lock_guard<mutex> guard(mx);
		if (mp.find(ip)==mp.end()) {
			mp[ip]=new HitCount();
		}

		return mp[ip]->tryAccept(system_clock::now());
	}

	unordered_map<string, HitCount*> mp;
	mutex mx;
};

int main() {
	Client client;

	for (int i=0; i<100; i++) {
		bool b=client.tryAccept("10.204.0.1");
		cout << "i=" << i << " " << b << endl;
	}

	for (int i=100; i<150; i++) {
		bool b=client.tryAccept("10.204.0.1");
		this_thread::sleep_for(milliseconds(100));
		cout << "i=" << i << " " << b << endl;
	}

	return 0;
}

3. Leaky bucket
package main

import (
	"fmt"
	"sync"
	"time"
)

type Bucket struct {
	mu       sync.Mutex
	capacity int64
	rate     int64
	water    int64
	lasttime time.Time
}

func NewBucket(rate, capacity int64) *Bucket {
	b := &Bucket{
		capacity: capacity,
		rate:     rate,
		lasttime: time.Now(),
	}

	return b
}

func (b *Bucket) tryAccept() bool {
	currtime := time.Now()
	left := b.water - int64(float64(b.rate)*currtime.Sub(b.lasttime).Seconds())
	if left > 0 {
		b.water = left
	} else {
		b.water = 0
	}

	if b.water < b.capacity {
		b.water++
		b.lasttime = currtime
		return true
	}
	return false
}

func main() {
	b := NewBucket(100, 100)
	for i := 0; i < 100; i++ {
		res := b.tryAccept()
		fmt.Println(i, res)
	}
	for i := 100; i < 150; i++ {
		time.Sleep(5 * time.Millisecond)
		res := b.tryAccept()
		fmt.Println(i, res)
	}
}

