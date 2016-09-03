Implement a circular buffer using an array.

class CircularBuffer {
	CircularBuffer(int capacity) {
		this->capacity=capacity;
		data.resize(capacity);
		head=0;
		tail=0;
		count=0;
	}

	void push(int val) {
		if (count==capacity) return;

		data[head]=val;
		head=(head+1)%capacity;
		count++;
	}

	void pop() {
		if (!isEmpty()) {
			tail=(tail+1)%capacity;
			count--;
		}
	}

	int top() {
		if (!isEmpty()) {
			return data[head];
		} else {
			return -1;
		}
	}

	bool isEmpty() {
		return count==0;
	}
private:
	int capacity;
	vector<int> data;
	int head;
	int tail;
	int count;
};

class Solution {
public:
	Solution(int n) {
		windowSize=n;
		count.resize(n,0);
		currIdx=0;
		countHour=0;
		countTenMin=0;
	}

	// called every minute
	void moveNext() {
		currIdx++;
		countHour-=count[currIdx];
		count[currIdx]=0;
	}
	void updateCount() {
		count[currIdx]++;
		countHour++;
	}

	int getLastHour() {
		return countHour;
	}

	int getLastTenMinute() {
		int sum=0;
		int i=currIdx;
		int cnt=10;
		while (cnt>0) {
			sum+=count[i];
			i=(i-1)%windowSize;
			cnt--;
		}
		return sum;
	}

	int getLastMinute() {
		return count[currIdx];
	}

private:
	vector<int> count;
	int currIdx;
	int windowSize;
	int countHour;
	int countTenMin;
};

int main() {
	Solution s(60);
	for (int i=0; i<20; i++) {
		s.updateCount();
		s.updateCount();
		s.moveNext();
	}
	int res=s.getLastMinute();
	cout << res << endl;
	int hour=s.getLastHour();
	cout << hour << endl;
	return 0;
}

