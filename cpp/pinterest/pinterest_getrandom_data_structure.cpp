data structure, add(), delete(), getRandom() in O(1)

class Solution {
public:
	void insert(int val) {
		auto iter=table.find(val);
		if (iter==table.end()) {
			data.push_back(val);
			table[val]=data.size()-1;
		}
	}

	void remove(int val) {
		auto iter=table.find(val);
		if (iter!=table.end()) {
			int lastVal=data[data.size()-1];
			int lastIdx=iter->second;
			swap(data[iter->second], data[data.size()-1]);
			table[lastVal]=lastIdx;
			data.pop_back();
		}
	}

	// return index of val
	int search(int val) {
		auto iter=table.find(val);
		if (iter!=table.end()) return iter->second;
		else return -1;
	}

	int getRandom() {
		int num=rand()%(data.size()-1);
		return data[num];
	}
private:
	vector<int> data;
	// value, index
	unordered_map<int, int> table;
};

int main() {
	Solution s;
	for (int i=0; i<10; i++) {
		s.insert(i);
	}
	s.remove(5);
	s.remove(9);
	s.insert(11);
	int res=s.getRandom();
	int pos=s.search(6);
	return 0;
}

