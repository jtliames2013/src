 keyValueStore 有四个method，add(key, value), remove(key), get(key), lastestKey() implement keyValueStore
前三个就和hashmap一样，最后一个返回最近访问的key

class KVStore {
public:
	struct Entry {
		int key;
		int val;
		Entry(int k, int v):key(k), val(v) {}
	};

	void add(int key, int value) {
		if (table.find(key)!=table.end()) {
			if (table[key]!=data.begin()) {
				data.erase(table[key]);
				data.push_front((*table[key]));
				table[key]=data.begin();
			}
			table[key]->val=value;
		} else {
			Entry e(key, value);
			data.push_front(e);
			table[key]=data.begin();
		}
	}

	void remove(int key) {
		if (table.find(key)!=table.end()) {
			data.erase(table[key]);
			table.erase(key);
		}
	}

	int get(int key) {
		if (table.find(key)==table.end()) return -1;
		if (table[key]!=data.begin()) {
			data.erase(table[key]);
			data.push_front(*table[key]);
			table[key]=data.begin();
		}
		return table[key]->val;
	}

	int lastkey() {
		if (data.empty()) return -1;
		return data.front().key;
	}
private:
	unordered_map<int, list<Entry>::iterator> table;
	list<Entry> data;
};

