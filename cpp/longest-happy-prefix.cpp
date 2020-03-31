1392. Longest Happy Prefix
Hard

105

10

Add to List

Share
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s. Return the longest happy prefix of s .

Return an empty string if no such prefix exists.

 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
Example 2:

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
Example 3:

Input: s = "leetcodeleet"
Output: "leet"
Example 4:

Input: s = "a"
Output: ""
 

Constraints:

1 <= s.length <= 10^5
s contains only lowercase English letters.

Rolling hash

class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size(), res=0;
        long h1=0, h2=0, pow=1;
        for (int i=0, j=n-1; j>0; ++i, --j) {
            int first=s[i]-'a', last=s[j]-'a';
            h1=(h1*base+first)%mod;
            h2=(h2+pow*last)%mod;
            pow=pow*base%mod;
            if (h1==h2) res=i+1;
        }
        return s.substr(0, res);
    }
private:
    const long base=256;
    const long mod=1e9+7;
};

2.
KMP

https://www.youtube.com/watch?v=GTJr8OvyEVQ
https://web.stanford.edu/class/cs97si/10-string-algorithms.pdf
class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> p(n);
        for (int j=0, i=1; i<n; ++i) {
            while (j>0 && s[i]!=s[j]) j=p[j-1];
            if (s[i]==s[j]) p[i]=++j;
        }
        return s.substr(0, p[n-1]);
    }
};


