国人小哥，上来先问了10分钟之前的项目。然后给了一道题，其实就是eval一个算式（题目描述问了半天才算搞明白。。汗）。和lc上稍微不同的地方是一个符号可以跟多个operand，比如(+ 5 6 7 (* 1 2 3)) 差不多这个样子

输入是 "+ 1 1 ( * 3 5 4 6)" 这种字符串,有+-*/(). 求值. 也就是求 1+1+(3*4*5*6).

class Solution {
public:
	int calc(int a, int b, char op) {
		switch (op) {
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a-b;
		default: return 0;
		}
	}

	bool isop(char c) {
		return c=='+' || c=='-' || c=='*' || c=='/';
	}

	int eval(string s) {
		int res=0, n=s.size();
		char op='+';
		bool hasNum=false;
		stack<int> results;
		stack<char> ops;
		stack<bool> hn;

		for (int i=0; i<n; i++) {
			if (isdigit(s[i])) {
				if (hasNum) res=calc(res, s[i]-'0', op);
				else {
					res=s[i]-'0';
					hasNum=true;
				}
			} else if (isop(s[i])) {
				op=s[i];
			} else if (s[i]=='(') {
				results.push(res);
				ops.push(op);
				hn.push(hasNum);
				hasNum=false;
				res=0;
				op='+';
			} else if (s[i]==')') {
				int r=results.top();
				results.pop();
				char c=ops.top();
				ops.pop();
				hasNum=hn.top();
				hn.pop();
				res=calc(res, r, c);
				op=c;

			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	string str1="(+ 5 6 7 (* 1 2 3))";
	string str2="+ 1 1 ( * 3 5 4 6)";
	cout << s.eval(str1) << endl;
	cout << s.eval(str2) << endl;
	return 0;
}

