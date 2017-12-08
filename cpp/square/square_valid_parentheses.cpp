2. 1: ((AB()(CD)  类似这种的string, return是否valie
2.2 ：(({{}gfajfd}[]><  类似这种string， return是否Valid， 增加了{}， <>, []
2.3 ： str同2.2， 但是要你打印出来那一块不match.

class Solution {
public:
	bool isNotParen1(char ch) {
		return ch!='(' && ch!=')';
	}

	bool isValid1(string s) {
		stack<char> stk;
		// letter should be inside parenthese if there is
		// (abc) or abc is valid, (abc()) or (()abc) is not
		for (int i=0; i<s.size();) {
			if (s[i]=='(') {
				// abc( is invalid
				if (i>0 && isNotParen1(s[i-1])) return false;
				stk.push(s[i]);
				i++;
			}
			else if (s[i]==')') {
				if (!stk.empty() && stk.top()=='(') stk.pop();
				else return false;
				i++;
			} else {
				// there should be no ) in stack
				if (i>0 && s[i-1]==')') return false;
				while (isNotParen1(s[i])) i++;
			}
		}

		if (stk.empty()) return true;
		else return false;
	}

	bool isNotParen2(char ch) {
		return ch!='(' && ch!=')' &&
  			   ch!='{' && ch!='}' &&
			   ch!='[' && ch!=']' &&
			   ch!='<' && ch!='>';
	}

	bool isValid2(string s) {
		stack<char> stk;
		for (int i=0; i<s.size();) {
			if (s[i]=='(' || s[i]=='{' || s[i]=='[' || s[i]=='<') {
				if (i>0 && isNotParen2(s[i-1])) return false;
				stk.push(s[i]);
				i++;
			} else if (s[i]==')' || s[i]=='}' || s[i]==']' || s[i]=='>') {
				if (!stk.empty() &&
					((s[i]==')' && stk.top()=='(') ||
					 (s[i]=='}' && stk.top()=='{') ||
					 (s[i]==']' && stk.top()=='[') ||
					 (s[i]=='>' && stk.top()=='<') )) {
					stk.pop();
					i++;
				} else {
					return false;
				}
			} else {
				if (i>0 && (s[i-1]==')' || s[i-1]=='}' || s[i-1]==']' || s[i-1]=='>')) return false;
				while (isNotParen2(s[i])) i++;
			}
		}

		if (stk.empty()) return true;
		else return false;
	}

	string isValid3(string s) {
		stack<char> stk;
		for (int i=0; i<s.size();) {
			if (s[i]=='(' || s[i]=='{' || s[i]=='[' || s[i]=='<') {
				if (i>0 && isNotParen2(s[i-1])) return s.substr(0, i+1);
				stk.push(s[i]);
				i++;
			} else if (s[i]==')' || s[i]=='}' || s[i]==']' || s[i]=='>') {
				if (!stk.empty() &&
					((s[i]==')' && stk.top()=='(') ||
					 (s[i]=='}' && stk.top()=='{') ||
					 (s[i]==']' && stk.top()=='[') ||
					 (s[i]=='>' && stk.top()=='<') )) {
					stk.pop();
					i++;
				} else {
					return s.substr(0, i+1);
				}
			} else {
				if (i>0 && (s[i-1]==')' || s[i-1]=='}' || s[i-1]==']' || s[i-1]=='>')) return s.substr(0, i+1);
				while (isNotParen2(s[i])) i++;
			}
		}

		if (stk.empty()) return "";
		else {
			string res;
			while (!stk.empty()) {
				res.insert(res.begin(), stk.top());
				stk.pop();
			}
			return res;
		}
	}
};

int main() {
	string str1="((AB)()(CD)EF)";
	string str2="(({}{gfajfd}))[]<>";
	string str3="(({{}(gfajfd)}[]<>";
	Solution sol;
	bool res1=sol.isValid1(str1);
	cout << "res1=" << res1 << endl;
	bool res2=sol.isValid2(str2);
	cout << "res2=" << res2 << endl;
	string res3=sol.isValid3(str3);
	cout << "res3=" << res3 << endl;

	return 0;
}

