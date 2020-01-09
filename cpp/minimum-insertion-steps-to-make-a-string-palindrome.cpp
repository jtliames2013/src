1312. Minimum Insertion Steps to Make a String Palindrome
Hard

109

4

Add to List

Share
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
Example 4:

Input: s = "g"
Output: 0
Example 5:

Input: s = "no"
Output: 1
 

Constraints:

1 <= s.length <= 500
All characters of s are lower case English letters.

Find the the longest common sequence between s1 and s2,
where s1 = s and s2 = reversed(s)

1. DP
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                dp[i][j]=s[i-1]==s[n-j]?dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return n-dp[n][n];
    }
};

2. 1D DP
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<int> dp(n+1);
        for (int i=1; i<=n; ++i) {
            int prev=dp[0];
            for (int j=1; j<=n; ++j) {
                int tmp=dp[j];
                dp[j]=s[i-1]==s[n-j]?prev+1:max(dp[j], dp[j-1]);
                prev=tmp;
            }
        }
        return n-dp[n];
    }
};

