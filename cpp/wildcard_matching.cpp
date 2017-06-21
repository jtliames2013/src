44. Wildcard Matching  
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
Hide Company Tags Google Snapchat Facebook
Hide Tags Dynamic Programming Backtracking Greedy String
Hide Similar Problems (H) Regular Expression Matching

[解题思路]
主要是*的匹配问题。p每遇到一个*，就保留住当前*的坐标和s的坐标，然后s从前往后扫描，如果不成功，则s++,重新扫描。

class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0, sIndex, pIndex;
        bool star=false;
        
        while (i<s.size()) {
            if (p[j]=='?') {
                i++;
                j++;
            } else if (p[j]=='*') {
                while (p[j]=='*') j++;
                if (j==p.size()) return true;
                star=true;
                sIndex=i;
                pIndex=j;
            } else {
                if (s[i]==p[j]) {
                    i++;
                    j++;
                } else {
                    if (star==false) return false;
                    else {
                        j=pIndex;
                        i=++sIndex;
                    }
                }
            }
        }
        
        while (p[j]=='*') j++;
        return j==p.size();
    }
};

