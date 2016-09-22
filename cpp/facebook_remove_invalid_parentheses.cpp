2. balance parentheses in a string 
例子：
"(a)()" -> "(a)()"
"((bc)" -> "(bc)"
")))a((" -> "a". 
"(a(b)" ->"(ab)" or "a(b)"

Note: balance的意思就是把原来string里unpaired的括号变成paired的形式。如果有多个可能的结果， 比如上述最后一种情况，我们就只需要输出一个对的结果即可，所以这点简化了题目的难度。
感受： 遍历string， 用一个stack存储每个open parenthesis的index，也就是'('的index, 每当遇到closed parenthesis就执行一次pop操作。
注意两种unbalanced的情况：
1. 出现多余的')':
    对应情况就是stack为空，但遇到了一个')'。
2. 出现多余的'(':
    对应情况就是遍历结束，stack未空

解决这两种情况即可。
对于java，我们需要把string转换成char array来做，因为在java中string is immutable.

follow-up:
Q：分析复杂度，问怎么不用stack来做？
A：想了一会儿，感觉用two-pointer可行，一个指头， 一个指尾， 头index找'('， 找到就移动尾index找')'。面试官虽然没说，但一开始反应有点惊讶

class Solution {
public:
	string removeInvalidParentheses(string s) {
		int count=0, open=0, close=0;
		for (auto c:s) {
			if (c=='(') count++;
			else if (c==')') {
				if (count==0) close++;
				else count--;
			}
		}
		open=count;
		if (open==0 && close==0) return s;
		string res;
		for (int i=0; i<s.size(); i++) {
			if (s[i]!='(' && s[i]!=')') res+=s[i];
			else if (s[i]=='(') {
				if (open>0) open--;
				else res+=s[i];
			} else {
				if (close>0) close--;
				else res+=s[i];
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	//string str="(a)()";
	//string str="((bc)";
	//string str=")))a((";
	string str="(a(b)";
	string res=s.removeInvalidParentheses(str);
	cout << res << endl;
	return 0;
}

