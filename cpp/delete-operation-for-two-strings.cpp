583. Delete Operation for Two Strings
DescriptionHintsSubmissionsSolutions
Total Accepted: 3145
Total Submissions: 7170
Difficulty: Medium
Contributors:
love_Fawn
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
Subscribe to see which companies asked this question.

Hide Tags String
Hide Similar Problems (H) Edit Distance

1. edit distance
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for (int i=0; i<=m; i++) dp[i][0]=i;
        for (int i=0; i<=n; i++) dp[0][i]=i;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                int delta=word1[i-1]==word2[j-1]?0:2;
                dp[i][j]=min(min(dp[i-1][j], dp[i][j-1])+1, dp[i-1][j-1]+delta);
            }
        }
        return dp[m][n];
    }
};

2. LCS
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for (int i=0; i<=m; i++) dp[i][0]=0;
        for (int i=0; i<=n; i++) dp[0][i]=0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                dp[i][j]=word1[i-1]==word2[j-1]?dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m+n-2*dp[m][n];
    }
};

