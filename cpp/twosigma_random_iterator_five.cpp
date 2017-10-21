第二题是 给一个random number的generator的interator写interator 其中要求生成的随机数可以被五整除。

class Iterator {
public:
	Iterator();
	virtual ~Iterator();
	int next();
	bool hasNext();
};

class IteratorFive: public Iterator {
	IteratorFive() : Iterator() {
		hasFive=false;
		num=0;
		tryAdvance();
	}

	void tryAdvance() {
		while (Iterator::hasNext()) {
			int n=Iterator::next();
			if (n%5==0) {
				hasFive=true;
				num=n;
				break;
			}
		}
	}

	int next() {
		if (!hasNext()) return 0;
		int res=num;
		tryAdvance();
		return res;
	}

	bool hasNext() {
		return hasFive;
	}

private:
	bool hasFive;
	int num;
};

