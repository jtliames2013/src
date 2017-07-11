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

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        int a=1, b=s[0]=='0'?0:1, c;
        for (int i=1; i<n; i++) {
            c=0;
            if (s[i]=='0' && s[i-1]=='0') return 0;
            if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')) c+=a;
            if (s[i]!='0') c+=b;
            a=b;
            b=c;
        }
        return b;
    }
};

