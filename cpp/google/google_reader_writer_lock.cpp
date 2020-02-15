1. Basic
class RWLock {
	RWLock() {
		count=0;
	}

	void ReaderLock() {
		unique_lock<mutex> lock(mtx);
		while (count<0) cv.wait(lock);
		count++;
	}

	void ReaderUnlock() {
		unique_lock<mutex> lock(mtx);
		count--;
		if (count==0) cv.notify_all();
	}

	void WriterLock() {
                unique_lock<mutex> lock(mtx);
		while (count!=0) cv.wait(lock);
		count--;
	}

	void WriteUnlock() {
                unique_lock<mutex> lock(mtx);
		count++;
		cv.notify_all();
	}

private:
	int count;
	mutex mtx;
	condition_variable cv;
};

2. avoid writer starvation
class RWLock {
	RWLock() {
		count=0;
		writerRequests=0;
	}

	void ReaderLock() {
                unique_lock<mutex> lock(mtx);
		while (count<0 || writerRequests>0) {
			cv.wait(lock);
		}
		count++;
	}

	void ReaderUnlock() {
                unique_lock<mutex> lock(mtx);
		count--;
		if (count==0) cv.notify_all();
	}

	void WriterLock() {
                unique_lock<mutex> lock(mtx);
		writerRequests++;
		while (count!=0) cv.wait(lock);
		count--;
		writerRequests--;
	}

	void WriteUnlock() {
                unique_lock<mutex> lock(mtx);
		count++;
		cv.notify_all();
	}

private:
	int count;
	int writerRequests;
	mutex mtx;
	condition_variable cv;
};

3. FIFO
// r r w r r r w r w r r r r
class RWLock {
	RWLock() {
		count=0;
		curr=0;
		index=0;
	}

	void ReaderLock() {
                unique_lock<mutex> lock(mtx);
		int i=index;
		while (count<0 || i>curr) {
			cv.wait(lock);
		}
		count++;
	}

	void ReaderUnlock() {
                unique_lock<mutex> lock(mtx);
		count--;
		if (count==0) cv.notify_all();
	}

	void WriterLock() {
                unique_lock<mutex> lock(mtx);
		int i=index++;
		while (count!=0 || i>curr) {
			cv.wait(lock);
		}
		count--;
	}

	void WriteUnlock() {
                unique_lock<mutex> lock(mtx);
		count++;
		curr++;
		cv.notify_all();
	}

private:
	int count;
	int curr;
	int index;
	mutex mtx;
	condition_variable cv;
};

