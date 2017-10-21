第二是printtimestamps with diff < 1和website太慢应该怎么办……面经上对于这个题目的意思一直都说的很不清楚，正确的说法是有两个blocking queue，每个queue里面存的是一个tuple ，我们想找到在这两个queue里面timestamp相差 <= 1的所有pair应该咋做。我一开始一直不理解为什么大家写的code都说要加锁，anyway我就先开始写了，反正大概就是先写calculatePair(queue q1,queueq2)的函数，然后假设是q2新来了一个timestamp，直接判断q1的front中的timestamp是否和q2.back()的timestamp相差值大于1，如果大于1不断pop即可。锁是出现在这儿的，因为两个queue都是blocking queue，也就是说如果调用int val= qs1.Take()，如果这个时候qs1没有来新data那么整个程序会block住，所以如果是一个while (true)的loop去调用calculate(q1, q2)然后calculate(q2, q1)的话整个程序很容易就block了，所以要开两个线程然后加个锁，这个锁应该锁在两个take()函数之后，然后运行完calculate()之后再release。（下面是follow up）答完之后他说this works，然后就问如果有多个queue，比如10个queue怎么办，我一看这个followup地上好像没说过……看来答的还可以，有戏……我就大概说了一个对每个queue都要维护一个pairwise的pointer headlist，这个可以用一个minHeap维护，然后如果队首的timestamp小于minHeap的最小值就把这个timestamp pop掉，他表示认可。

class Stream{
	void add(double timestamp, int type) {
		if (type==1) {
			lock_guard<mutex> guard(mx1);
			q1.push_back(timestamp);
			cv1.notify_one();
		} else {
			lock_guard<mutex> guard(mx2);
			q2.push_back(timestamp);
			cv2.notify_one();
		}
	}

	void print1() {
		while (1) {
			unique_lock<mutex> lk(mx1);
			cv1.wait(lk);
			double t1;
			double t1=q1.back();
			lock_guard<mutex> guard(mx2);
			while (t1-q2.front()>1) q2.pop_front();
			for (int i=0; i<q1.size(); i++) {
				cout << q2[i] << " " << t1 << endl;
			}
		}
	}

	void print2() {
		while (1) {
			unique_lock<mutex> lk(mx2);
			cv1.wait(lk);
			double t2;
			double t2=q2.back();
			lock_guard<mutex> guard(mx1);
			while (t1-q1.front()>1) q1.pop_front();
			for (int i=0; i<q1.size(); i++) {
				cout << q1[i] << " " << t2 << endl;
			}
		}
	}

	void print(deque<double>& q1, deque<double>& q2) {
		double t1=q1.back();
		while (t1-q2.front()>1) q2.pop_front();
		for (int i=0; i<q2.size(); i++) {
			cout << q2[i] << " " << t1 << endl;
		}
	}
	void print(vector<double> v1, vector<double> v2) {
		int m=v1.size(), n=v2.size(), i=0, j=0;
		while (i<m || j<n) {
			if (i==m) {
				q2.push_back(v2[j++]);
				print(q1, q2);
			}
			else if (j==n) {
				q1.push_back(v1[i++]);
				print(q2, q1);
			}
			else {
				if (v1[i]<v2[j]) {
					q1.push_back(v1[i++]);
					print(q1, q2);
				} else {
					q2.push_back(v2[j++]);
					print(q2, q1);
				}
			}
		}
	}

private:
	deque<double> q1;
	deque<double> q2;
	mutex mx1;
	mutex mx2;
	conditional_variable cv1;
	conditional_variable cv2;
};

