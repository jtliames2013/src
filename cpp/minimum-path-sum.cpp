64. Minimum Path Sum Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 105901
Total Submissions: 280339
Difficulty: Medium
Contributor: LeetCode
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Subscribe to see which companies asked this question.

Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Unique Paths (H) Dungeon Game

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j==0) dp[i][j]=0;
                else if (i==0) dp[i][j]=dp[i][j-1];
                else if (j==0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]+=grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

2. Use 1D dp array
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        vector<int> dp(n, INT_MAX);
        dp[0]=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (j>0) dp[j]=min(dp[j-1], dp[j]);
                dp[j]+=grid[i][j];
            }
        }
        return dp[n-1];
    }
};
