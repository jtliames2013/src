实现Version Control（具体是存 <key, value> with timestamp， 当输入time和key时要给出value。还有些其他功能实现，比如size、remove、add。但主要思想就是这样。）

class Solution {
public:
	void add(int key, int value, float time) {
		table[key][time]=value;
	}

	void remove(int key, float time) {
		table[key].erase(time);
	}

	int get(int key, float time) {
		if (table.find(key)!=table.end()) {
			if (table[key].find(time)!=table[key].end()) {
				return table[key][time];
			}
		}

		return -1;
	}
private:
	map<int, map<float,int> > table;
};

int main() {
	Solution s;

	return 0;
}

