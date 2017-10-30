Airbnb: Mini Parser
http://yuanhsh.iteye.com/blog/2230314

实现一个mini parser, 输入是以下格式的string:"324" or"[123,456,[788,799,833],[[]],10,[]]"
要求输出:324 or [123,456,[788,799,833],[[]],10,[]].
也就是将字符串转换成对应的格式的数据.
输入一个数组的字符串, 要返回一个数组, 里面每一个元素是要么一个整数, 要么是一个数组.
但是注意数组可以多层嵌套. 

  class NestedInteger {
	  bool isInt;
	  int val;
	  vector<NestedInteger*> children;
  public:
	  NestedInteger(): val(0), isInt(false) {}
	  NestedInteger(int i): val(i), isInt(true) {}
	  bool isInteger() { return isInt; }
	  int getInteger() { return val; }
	  void addList(NestedInteger *ni) {
		  children.push_back(ni);
	  }
	  void print() {
		  if (isInt) {
			  cout << val;
		  } else {
			  cout << "[";
			  for (int i=0; i<children.size(); i++) {
				  if (i>0) cout << ",";
				  children[i]->print();
			  }
			  cout << "]";
		  }
	  }
  };

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
  	//NestedInteger ni=s.parse("[123,456,[788,799,833],[[]],10,[]]");
  	NestedInteger ni=s.parse("324");
  	s.print(ni);
    	return 0;
  }

