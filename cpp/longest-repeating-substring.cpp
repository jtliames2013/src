1062. Longest Repeating Substring
Medium

97

6

Favorite

Share
Given a string S, find out the length of the longest repeating substring(s). Return 0 if no repeating substring exists.

 

Example 1:

Input: "abcd"
Output: 0
Explanation: There is no repeating substring.
Example 2:

Input: "abbaba"
Output: 2
Explanation: The longest repeating substrings are "ab" and "ba", each of which occurs twice.
Example 3:

Input: "aabcaabdaab"
Output: 3
Explanation: The longest repeating substring is "aab", which occurs 3 times.
Example 4:

Input: "aaaaa"
Output: 4
Explanation: The longest repeating substring is "aaaa", which occurs twice.
 

Note:

The string S consists of only lowercase English letters from 'a' - 'z'.
1 <= S.length <= 1500

Amazon
|
2

class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int res=0, n=S.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int i=1; i<=n; ++i) {
            for (int j=i+1; j<=n; ++j) {
                if (S[i-1]==S[j-1]) dp[i][j]=1+dp[i-1][j-1];
                res=max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};

