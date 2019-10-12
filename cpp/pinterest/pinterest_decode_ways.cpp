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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <limits.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size=s.size();
        if (size==0) return 0;
        vector<int> dp(size+1, 0);
        dp[0]=1;
        dp[1]=1;
        if (s[0]=='0') dp[1]=0;
        for (int i=2; i<=size; i++) {
            if (s[i-1]>'0') dp[i]=+dp[i-1];
            if (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')) {
                dp[i]+=dp[i-2];
            }
        }
        
        return dp[size];
  }
};

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        vector<int> dp(n,0);
        if (s[0]!='0') dp[0]=1;
        for (int i=1; i<n; i++) {
            if (s[i]!='0') dp[i]=dp[i-1];
            if (s[i-1]=='1' || (s[i-1]=='2'&&s[i]<='6')) {
                if (i<2) dp[i]+=1;
                else dp[i]+=dp[i-2];
            }
        }
        
        return dp[n-1];
  }
};

class Solution {
public:
	void findDecode(vector<string>& res, string& s, string& expr, int start) {
		if (start==s.size()) {
			res.push_back(expr);
			return;
		}

		if (s[start]!='0') {
			expr.push_back(s[start]-'1'+'A');
			findDecode(res, s, expr, start+1);
			expr.erase(expr.end()-1);

			if (start+1<s.size() && (s[start]=='1' || (s[start]=='2' && s[start+1]<='6'))) {
				char ch='A'+(s[start]-'0')*10+(s[start+1]-'1');
				expr.push_back(ch);
				findDecode(res, s,  expr, start+2);
				expr.erase(expr.end()-1);
			}
		}
	}

    vector<string> numDecodings(string s) {
    	vector<string> res;
    	string expr;
    	findDecode(res, s, expr, 0);

    	return res;
    }
};

void printVector(vector<string> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	Solution s;
	string str="123";
	vector<string> res=s.numDecodings(str);
	printVector(res);

	return 0;
}

