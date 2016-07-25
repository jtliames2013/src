给定一堆人名，{“a”， “b”， “c”, "d", "e"}， 输出 "a, b, c, d and e". Follow up: 只输出前K个。比如K=2， 输出“a, b and 3 others”

class Solution {
public:
	void removeEmpty(vector<string>& names) {
		for (auto iter=names.begin(); iter!=names.end();) {
			if (iter->empty()) {
				names.erase(iter);
			} else {
				iter++;
			}
		}
	}
	string getEnglistFormat(vector<string> names) {
		string res;
		removeEmpty(names);
		int size=names.size();
		for (int i=0; i<size; i++) {
			if (i==0) res+=names[i];
			else {
				if (i==size-1) {
					res+=" and " + names[i];
				} else {
					res+=", " + names[i];
				}
			}
		}

		return res;
	}

	string getEnglistFormatFirstK(vector<string> names, int k) {
		string res;
		removeEmpty(names);
		int size=names.size();
		if (k==0) return res;
		for (int i=0; i<size; i++) {
			if (i==k) {
				res+=" and " + to_string(size-k) + " others";
				break;
			}
			if (i==0) res+=names[i];
			else {
				res+=", " + names[i];
			}
		}

		return res;
	}
};

int main() {
	//vector<string> names={"alice"};
	//vector<string> names={"alice", "bob"};
	vector<string> names={"alice","", "bob","","","", "john", "neil", "", "tom"};
	Solution s;
	string res=s.getEnglistFormat(names);
	string resk=s.getEnglistFormatFirstK(names, 2);
	cout << res << endl;
	cout << resk << endl;
	return 0;
}

