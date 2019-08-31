62. Unique Paths  
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Hide Company Tags Bloomberg
Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Unique Paths II (M) Minimum Path Sum (H) Dungeon Game

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==0||n==0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0]=1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {  
                if (i>0) dp[i][j]+=dp[i-1][j];
                if (j>0) dp[i][j]+=dp[i][j-1];                
            }
        }
        return dp[m-1][n-1];
    }
};

2. 1D dp array
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        dp[0]=1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (j>0) dp[j]+=dp[j-1];
            }
        }
        
        return dp[n-1];
    }
};
