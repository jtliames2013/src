class Solution {
public:
	void print(NestedInteger ni) {
		ni.print();
		cout << endl;
	}

	NestedInteger parse(string s) {
		NestedInteger res;
		int i=0;
		int num=0;
		stack<NestedInteger*> stk;
		while (i<s.size()) {
			if (isdigit(s[i])) {
				num=0;
				while (isdigit(s[i])) {
					num=num*10+s[i]-'0';
					i++;
				}
				NestedInteger *ni = new NestedInteger(num);
				if (!stk.empty()) stk.top()->addList(ni);
				else {
					// do some validation
					if (i<s.size()) cout<< "invalid format" << endl;
					return *ni;
				}
			} else if (s[i]=='[') {
				NestedInteger *ni=new NestedInteger();
				if (!stk.empty()) stk.top()->addList(ni);
				stk.push(ni);
				i++;
			} else if (s[i]==']') {
				if (stk.size()==1) res=*stk.top();
				stk.pop();
				i++;
			} else {
				i++;
			}
		}

		return res;
	}
  };

int main()
{
	Solution s;
	NestedInteger ni=s.parse("[123,456,[788,799,833],[[]],10,[]]");
	//NestedInteger ni=s.parse("324");
	s.print(ni);
  	return 0;
}

