1. list and set
class notavail: public exception {
	virtual const char* what() const throw() {
		return "Not Available";
	}
} myex;

class Solution {
public:
	Solution(int maxNumbers) {
		this->maxNumbers = maxNumbers;
		for (int i=0; i<maxNumbers; i++) available.push_back(i);
	}

	int allocate() {
		if (available.empty()) {
			throw myex;
		}

		int res=available.front();
		used.insert(res);
		available.pop_front();
		return res;
	}

	void deallocate(int id) {
		if (id<0 || id>=maxNumbers || used.find(id)==used.end()) {
			throw myex;
		}

		used.erase(id);
		available.push_back(id);
	}
private:
	int maxNumbers;
	list<int> available;
	unordered_set<int> used;
};

2. bit array
class notavail: public exception {
	virtual const char* what() const throw() {
		return "Not Available";
	}
} myex;

class Solution {
public:
	Solution (int maxNumbers) {
		this->maxNumbers = maxNumbers;
		used.resize(maxNumbers);
	}

	int allocate() {
		for (int i=0; i<maxNumbers; i++) {
			if (!used[i]) {
				used[i]=true;
				return i;
			}
		}
		throw myex;
	}

	void deallocate(int id) {
		if (id<0 || id>=maxNumbers || !used[id]) {
			throw myex;
		}
		used[id]=false;
	}
private:
	int maxNumbers;
	vector<bool> used;
};

3. bit array with optimization
class notavail: public exception {
	virtual const char* what() const throw() {
		return "Not Available";
	}
} myex;

class Solution {
public:
	Solution (int maxNumbers) {
		this->maxNumbers = maxNumbers;
		lastBucket=maxNumbers%size;
		buckets.resize(maxNumbers/size+1);
		used.resize(maxNumbers);
	}

	int allocate() {
		for (int i=0; i<buckets.size(); i++) {
			if ((i<buckets.size()-1 && buckets[i]<size) ||
				(i==buckets.size() && buckets[i]<lastBucket)) {
				int range=i<buckets.size()-1?size:lastBucket;
				for (int j=0; j<range; j++) {
					int id=i*size+j;
					if (!used[id]) {
						used[id]=true;
						buckets[i]++;
						return id;
					}
				}
			}
		}
		throw myex;
	}

	void deallocate(int id) {
		if (id<0 || id>=maxNumbers || !used[id]) {
			throw myex;
		}
		used[id]=false;
		buckets[id/size]--;
	}
private:
	int maxNumbers;
	const int size=1024;
	int lastBucket=0;
	vector<bool> used;
	vector<int> buckets;
};

4. segment tree
class notavail: public exception {
	virtual const char* what() const throw() {
		return "Not Available";
	}
} myex;

class Solution {
public:
	Solution (int maxNumbers) {
		this->maxNumbers = maxNumbers;
		this->size=2*maxNumbers;
		used.resize(size);
	}

	void update(int i) {
		while (i>0) {
			int l=i, r=i;
			if (i%2==0) r=i+1;
			else l=i-1;
			used[i/2]=used[l] && used[r];
			i/=2;
		}
	}

	int allocate() {
		int i=1;
		while (i<size) {
			if (used[i]) {
				throw myex;
			} else {
				if (i>=maxNumbers) {
					used[i]=true;
					update(i);
					return i;
				} else {
					if (!used[2*i]) i=2*i;
					else i=2*i+1;
				}
			}
		}
	}

	void deallocate(int id) {
		int i=id+maxNumbers;
		if (id<0 || id>=maxNumbers || !used[i]) {
			throw myex;
		}
		used[i]=false;
		update(i);
	}
private:
	int maxNumbers;
	int size;
	vector<bool> used;
};

