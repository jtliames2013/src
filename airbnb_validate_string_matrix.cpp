给你一个字符对的转换matrix，表示这个字符对会转化成一个字符(但是有的字符对可能有多个能够转化成的字符，原文是nondeterministic)。以及若干个合法的终点(最顶上那一个点)状态，多次询问，每次一个字符串如果有一个方法能够走到合法状态就算是YES，否则NO.
解法：记忆化搜索，记录所有中间状态。因为转化矩阵和合法终点都是固定的，某个字符串要不永远是YES，要不永远是NO

class Solution {
public:
	Solution(vector<vector<set<char> > > matrix, set<string> accept) {
		this->matrix=matrix;
		this->accept=accept;
	}

	bool isValidString(string& s) {
		if (accept.find(s)!=accept.end()) {
			validStrings.insert(s);
			return true;
		} else if (validStrings.find(s)!=validStrings.end()) {
			return true;
		} else if (invalidStrings.find(s)!=invalidStrings.end()) {
			return false;
		}

		vector<string> res;
		string expr;
		getString(s, res, expr, 0);
		for (int i=0; i<res.size(); i++) {
			cout << res[i] << endl;
			if (isValidString(res[i])) {
				validStrings.insert(res[i]);
				return true;
			} else {
				invalidStrings.insert(res[i]);
			}
		}
		return false;
	}

	void getString(string& s, vector<string>& res, string& expr, int start) {
		if (start>=s.size()-1) {
			if (!expr.empty()) {
				res.push_back(expr);
			}
			return;
		}

		int i=s[start]-'a';
		int j=s[start+1]-'a';
		for (auto ch:matrix[i][j]) {
			expr.push_back(ch);
			getString(s, res, expr, start+1);
			expr.erase(expr.end()-1);
		}
	}

	bool isValid(string s) {
		return isValidString(s);
	}

private:
	vector<vector<set<char> > > matrix;
	set<string> accept;
	set<string> validStrings;
	set<string> invalidStrings;
};

int main() {
	vector<vector<set<char> > > matrix= {{{'a'},{'b'},{'c'},{'d'}}, {{'a'},{'b'},{'c'},{'d'}}, {{'a'},{'b'},{'c'},{'d'}}, {{'a'},{'b'},{'c'},{'d'}}};
	set<string> accept={"cd", "ab"};
	Solution s(matrix, accept);
	bool res=s.isValid("abcd");
	res=s.isValid("aabb");
	return 0;
}

2.
class Solution {
public:
	Solution(vector<vector<set<char> > > matrix, set<string> accept) {
		this->matrix=matrix;
		this->accept=accept;
	}

	bool isValidString(string& s) {
		if (accept.find(s)!=accept.end()) {
			validStrings.insert(s);
			return true;
		} else if (validStrings.find(s)!=validStrings.end()) {
			return true;
		} else if (invalidStrings.find(s)!=invalidStrings.end()) {
			return false;
		}

		string expr;
		if (s.size()==1) {
			// no need to go next level
			invalidStrings.insert(s);
			return false;
		} else {
			return validateNextString(s, expr, 0);
		}
	}

	bool validateNextString(string& s, string& expr, int start) {
		if (start>=s.size()-1) {
			cout << "expr=" << expr << endl;
			if (!expr.empty()) {
				if (isValidString(expr)) {
					validStrings.insert(expr);
					return true;
				} else {
					invalidStrings.insert(expr);
				}
			}
			return false;
		}

		int i=s[start]-'a';
		int j=s[start+1]-'a';
		for (auto ch:matrix[i][j]) {
			expr.push_back(ch);
			if (validateNextString(s, expr, start+1)==true) return true;
			expr.erase(expr.end()-1);
		}
		return false;
	}

	bool isValid(string s) {
		return isValidString(s);
	}

private:
	vector<vector<set<char> > > matrix;
	set<string> accept;
	set<string> validStrings;
	set<string> invalidStrings;
};

int main() {
	vector<vector<set<char> > > matrix= {{{'a'},{'a','b'},{'c'},{'d'}}, {{'a'},{'b'},{'c'},{'d'}}, {{'a'},{'b'},{'c'},{'d'}}, {{'a'},{'b'},{'c'},{'d'}}};
	set<string> accept={"cd", "ab"};
	Solution s(matrix, accept);
	bool res=s.isValid("abcd");
	res=s.isValid("aabb");
	return 0;
}

