就是按格式打印json，之前用过json不记得了格式细节了，店面小哥说无所谓，就打印就可以了
http://jsonprettyprint.com/. 1point3acres.com/bbs
类似这种的， 输入[1,2,3, {"id": 1, "name": "wang", "tag":[1,"home",2], "price":234}]
要求打出来这个
[  1,  2,  3,  {    "id": 1,    "name": "wang",    "tag": [      1,      "home",      2    ],    "price": 234  }]

class Solution {
public:
	string printJson(string s) {
		string res;
		string indent;
		char prev;

		for (int i=0; i<s.size(); i++) {
			if (isspace(s[i])) continue;
			if (s[i]=='}' || s[i]==']') indent.pop_back();
			if (prev=='{' || prev=='[' || prev==',' || s[i]=='}' || s[i]==']') {
            // if (prev=='{' || prev=='[' || prev==',' || s[i]=='[' || s[i]=='}' || s[i]==']') {
				res+='\n';
				res+=indent;
			}
			if (s[i]=='{' || s[i]=='[') indent.push_back('\t');
			res+=s[i];
			prev=s[i];
		}
		return res;
	}
};

int main()
{
	Solution s;
	//string str="[1,2,3, {\"id\": 1, \"name\": \"wang\", \"tag\":[1,\"home\",2], \"price\":234}]";
	string str="[\"foo\", {\"bar\":[\"baz\",null,1.0,2]}]";
	cout << s.printJson(str) << endl;

	return 0;
}

