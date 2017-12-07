1. Basic
class RWLock {
	RWLock() {
		count=0;
	}

	void ReaderLock() {
		mx.lock();
		while (count<0) {
			unique_lock<mutex> lk(mx);
			cv.wait(lk);
		}
		count++;
		mx.unlock();
	}

	void ReaderUnlock() {
		mx.lock();
		count--;
		if (count==0) cv.notify_all();
		mx.unlock();
	}

	void WriterLock() {
		mx.lock();
		while (count!=0) {
			unique_lock<mutex> lk(mx);
			cv.wait(lk);
		}
		count--;
		mx.unlock();
	}

	void WriteUnlock() {
		mx.lock();
		count++;
		cv.notify_all();
		mx.unlock();
	}

private:
	int count;
	mutex mx;
	condition_variable cv;
};

2. avoid writer starvation
class RWLock {
	RWLock() {
		count=0;
		writerRequests=0;
	}

	void ReaderLock() {
		mx.lock();
		while (count<0 || writerRequests>0) {
			unique_lock<mutex> lk(mx);
			cv.wait(lk);
		}
		count++;
		mx.unlock();
	}

	void ReaderUnlock() {
		mx.lock();
		count--;
		if (count==0) cv.notify_all();
		mx.unlock();
	}

	void WriterLock() {
		mx.lock();
		writerRequests++;
		while (count!=0) {
			unique_lock<mutex> lk(mx);
			cv.wait(lk);
		}
		count--;
		writerRequests--;
		mx.unlock();
	}

	void WriteUnlock() {
		mx.lock();
		count++;
		cv.notify_all();
		mx.unlock();
	}

private:
	int count;
	int writerRequests;
	mutex mx;
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
		mx.lock();
		int i=index;
		while (count<0 || i>curr) {
			unique_lock<mutex> lk(mx);
			cv.wait(lk);
		}
		count++;
		mx.unlock();
	}

	void ReaderUnlock() {
		mx.lock();
		count--;
		if (count==0) cv.notify_all();
		mx.unlock();
	}

	void WriterLock() {
		mx.lock();
		int i=index++;
		while (count!=0 || i>curr) {
			unique_lock<mutex> lk(mx);
			cv.wait(lk);
		}
		count--;
		mx.unlock();
	}

	void WriteUnlock() {
		mx.lock();
		count++;
		curr++;
		cv.notify_all();
		mx.unlock();
	}

private:
	int count;
	int curr;
	int index;
	mutex mx;
	condition_variable cv;
};

