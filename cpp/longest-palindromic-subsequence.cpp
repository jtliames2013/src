516. Longest Palindromic Subsequence Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 8751
Total Submissions: 20619
Difficulty: Medium
Contributors:
Stomach_ache
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming
Hide Similar Problems (M) Longest Palindromic Substring

dp[i][j]: the longest palindromic subsequence's length of substring(i, j)
State transition:
dp[i][j] = dp[i+1][j-1] + 2 if s.charAt(i) == s.charAt(j)
otherwise, dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1])
Initialization: dp[i][i] = 1

1. DP
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        if (n==0) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l=1; l<=n; l++) {
            for (int i=0; i+l<=n; i++) {
                if (l==1) dp[i][i+l-1]=1;
                else {
                    dp[i][i+l-1]=s[i]==s[i+l-1]?dp[i+1][i+l-2]+2:max(dp[i+1][i+l-1], dp[i][i+l-2]);
                }
            }
        }
        return dp[0][n-1];
    }
};

2. DFS
class Solution {
public:
    int dfs(string& s, vector<vector<int>>& dp, int start, int end) {
        if (dp[start][end]!=INT_MIN) return dp[start][end];
        if (start==end) return 1;
        if (start>end) return 0;
        
        if (s[start]==s[end]) {
            dp[start][end]=dfs(s, dp, start+1, end-1)+2;
        } else {
            dp[start][end]=max(dfs(s, dp, start+1, end), dfs(s, dp, start, end-1));
        }
        return dp[start][end];
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        if (n==0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return dfs(s, dp, 0, n-1);
    }
};

