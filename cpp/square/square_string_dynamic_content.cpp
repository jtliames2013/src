题目是字串处理, 一个字串里会有一些dynamic content, 把dynamic content运算完后回传String
dynamic content有两种, 
1. integer 相加: #{100 + 200 + 300} = 600
2. string 相加:#{'abc' +'def'} = abcdef
dynamic content里可以有任意的空格, 及复数个operand
一个字串可以含有多个dynamic content

ex: "Hello: #{100 + 200 + 300}" = "Hello: 600"; "Hello: #{'abc' +'def'}" = "Hello: abcdef"

class Solution {
public:
	string process(string& str) {
		string res;
		size_t n=str.size();
		size_t i=0;
		for (; i<n; i++) {
			if (str[i]=='#') break;
		}
		res+=str.substr(0, i);
		i+=2;
		if (i>=n)  return res;

		bool isNum=isdigit(str[i]);
		if (isNum) {
			int total=0;
			for (; i<n; ) {
				if (isdigit(str[i])) {
					int num=0;
					while (i<n && isdigit(str[i])) {
						num=num*10+str[i]-'0';
						i++;
					}
					total+=num;
				} else {
					i++;
				}
			}
			res+=to_string(total);
		} else {
			for (; i<n; ) {
				if (str[i]=='\'') {
					int j=i+1;
					while (j<n && str[j]!='\'') j++;
					res+=str.substr(i+1, j-i-1);
					i=j+1;
				} else {
					i++;
				}
			}
		}

		return res;
	}
};

int main() {
	Solution s;
	string str="Hello: #{100 + 200 + 300}";
	cout << s.process(str) << endl;

	string str2="Hello: #{'abc' +'def'}";
	cout << s.process(str2) << endl;
	return 0;
}


