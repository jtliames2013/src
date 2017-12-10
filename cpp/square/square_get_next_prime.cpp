设计class,实现 getNextPrimeNumber()

class Solution {
public:
	Solution() {
		currNum=1;
	}

	int getNextPrimeNumber() {
		currNum++;
		if (currNum<=2) return currNum;

		if ((currNum& 0x1)==0) currNum++;
		for (; !isPrime(currNum); currNum+=2);

		return currNum;
	}
private:
	bool isPrime(int num) {
		for (int i=3; ; i+=2) {
			int q=num/i;
			if (q<i) return true;
			if (num==q*i) return false;
		}
		return true;
	}

	int currNum;
};

int main() {
	Solution s;
	for (int i=0; i<100; i++) cout << s.getNextPrimeNumber() << " ";
	cout << endl;
	return 0;
}

