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

2. no array
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        int a=1;
        int b=s[0]=='0'?0:1;
        if (n==1) return b;
        int c;
        for (int i=1; i<n; i++) {
            c=0;
            if (s[i]=='0' && s[i-1]=='0') return 0;
            if (s[i]!='0') c+=b;
            if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')) c+=a;
            a=b;
            b=c;
        }
        return c;
    }
};

int main()
{
	return 0;
}

