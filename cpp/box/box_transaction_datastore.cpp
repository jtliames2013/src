#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <thread>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>

using namespace std;

#define INVALID INT_MIN

// record previous state of the key
struct Log {
	string key;
	int valFrom; // new value
	int valTo; // old value
	bool isNull;
	bool isBegin;
	Log(string k, int f, int t, bool n, bool b):key(k), valFrom(f), valTo(t), isNull(n), isBegin(b) {}
};

class DataStore {
public:
	DataStore() {
		begins=0;
	}

	void set(string key, int val) {
		if (begins>0) {
			if (table.find(key)!=table.end()) {
				transactionLogs.push_back({key, val, table[key], false, false});
			} else {
				transactionLogs.push_back({key, val, INVALID, true, false});
			}
		}
		if (table.find(key)!=table.end()) valueCount[table[key]]--;
		table[key]=val;
		valueCount[val]++;
	}

	int get(string key) {
		if (table.find(key)!=table.end()) {
			return table[key];
		} else {
			return INVALID;
		}
	}

	int count(int val) {
		return valueCount[val];
	}

	void deleteKey(string key) {
		if (table.find(key)!=table.end()) {
			if (begins>0) {
				transactionLogs.push_back({key, INVALID, table[key], false, false});
			}
			valueCount[table[key]]--;
			table.erase(key);
		}
	}

	void begin() {
		begins++;
		transactionLogs.push_back({"", 0, 0, false, true});
	}

	void commit() {
		begins=0;
		transactionLogs.clear();
	}

	void rollback() {
		if (begins>0) {
			for (size_t i=transactionLogs.size()-1; i>=0; i--) {
				if (transactionLogs[i].isBegin) {
					begins--;
					transactionLogs.pop_back();
					break;
				} else if (transactionLogs[i].isNull) {
					valueCount[transactionLogs[i].valFrom]--;
					table.erase(transactionLogs[i].key);
				} else {
					if (transactionLogs[i].valFrom!=INVALID) {
						valueCount[transactionLogs[i].valFrom]--;
					}
					valueCount[transactionLogs[i].valTo]++;
					table[transactionLogs[i].key]=transactionLogs[i].valTo;
				}
				transactionLogs.pop_back();
			}
		}
	}

private:
	unordered_map<string, int> table;
	unordered_map<int, int> valueCount;
	vector<Log> transactionLogs;
	int begins;
};

int main()
{
	DataStore kvstore;

	string line;
	while (cin) {
		cout << ">>>";
		getline(cin, line);
		if (line=="END") return 0;
		string op, key, value;
		istringstream iss(line);
		getline(iss, op, ' ');

		if (op=="SET") {
			getline(iss, key, ' ');
			getline(iss, value, ' ');
			int val=stoi(value);

			kvstore.set(key, val);
		} else if (op=="GET") {
			getline(iss, key, ' ');

			int val=kvstore.get(key);
			if (val!=INVALID) {
				cout << kvstore.get(key) << endl;
			} else {
				cout << "NULL" << endl;
			}
		} else if (op=="DELETE") {
			getline(iss, key, ' ');

			kvstore.deleteKey(key);
		} else if (op=="BEGIN") {
			kvstore.begin();
		} else if (op=="COUNT") {
			getline(iss, value);
			int val=stoi(value);
			cout << kvstore.count(val) << endl;
		} else if (op=="ROLLBACK") {
			kvstore.rollback();
		} else if (op=="COMMIT") {
			kvstore.commit();
		} else {
			cout << "unknown command " + line << endl;
			break;
		}
	}
	return 0;
}

