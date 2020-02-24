91. Decode Ways  
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Hide Company Tags Microsoft Uber Facebook
Hide Tags Dynamic Programming String

1.
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        if (s[0]=='0') return 0;
        unsigned int a=1, b=1, c;
        for (int i=1; i<n; ++i) {
            c=0;
            if (s[i]=='0' && (s[i-1]<'1' || s[i-1]>'2')) return 0;
            if (s[i]!='0') c+=b;
            if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')) c+=a;
            a=b;
            b=c;
        }
        return b;
    }
};

2. Output all strings
class Solution {
public:
	void dfs(vector<string>& res, string& output, string& s, int start) {
		if (start==s.size()) {
			res.push_back(output);
			return;
		}
		if (s[start]!='0') {
			output.push_back('A'+s[start]-'1');
			dfs(res, output, s, start+1);
			output.pop_back();
		}
		if (start<s.size()-1 && ((s[start]=='1') || (s[start]=='2' && s[start+1]<='6'))) {
			int num=(s[start]-'0')*10+s[start+1]-'0';
			output.push_back('A'+num-1);
			dfs(res, output, s, start+2);
			output.pop_back();
		}
	}
    vector<string> getDecodings(string s) {
        vector<string> res;
        string output;
    	dfs(res, output, s, 0);
        return res;
    }
};

