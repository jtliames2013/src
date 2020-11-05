1638. Count Substrings That Differ by One Character
Medium

58

49

Add to List

Share
Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

Return the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.
​​Example 2:
Input: s = "ab", t = "bb"
Output: 3
Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
("ab", "bb")
("ab", "bb")
("ab", "bb")
​​​​The underlined portions are the substrings that are chosen from s and t.
Example 3:
Input: s = "a", t = "a"
Output: 0
Example 4:

Input: s = "abe", t = "bbc"
Output: 10
 

Constraints:

1 <= s.length, t.length <= 100
s and t consist of lowercase English letters only.

1.
class Solution {
public:
    int countSubstrings(string s, string t) {
        int res=0;
        for (int i=0; i<s.size(); ++i) {
            for (int j=0; j<t.size(); ++j) {
                int diff=0;
                for (int k=0; k<min(s.size()-i, t.size()-j); ++k) {
                    if (s[i+k]!=t[j+k]) diff++;
                    if (diff>1) break;
                    res+=diff;
                }
            }
        }

        return res;
    }
};

2.
class Solution {
public:
    int countSubstrings(string s, string t) {
        int res=0, m=s.size(), n=t.size();
        vector<vector<int>> l(101, vector<int>(101)), r(101, vector<int>(101));
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (s[i-1]==t[j-1]) l[i][j]=1+l[i-1][j-1];
            }
        }

        for (int i=m-2; i>=0; --i) {
            for (int j=n-2; j>=0; --j) {
                if (s[i+1]==t[j+1]) r[i][j]=1+r[i+1][j+1];
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (s[i]!=t[j]) {
                    res+=(l[i][j]+1)*(r[i][j]+1);
                }
            }
        }

        return res;
    }
};
