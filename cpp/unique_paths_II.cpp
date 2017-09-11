63. Unique Paths II  
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Hide Company Tags Bloomberg
Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Unique Paths

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if (m==0) return 0;
        int n=obstacleGrid[0].size();
        if (n==0) return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0]=obstacleGrid[0][0]==0?1:0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (obstacleGrid[i][j]==0) {
                    if (i>0) dp[i][j]+=dp[i-1][j];
                    if (j>0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }    
};

2. Use 1D dp array
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if (m==0) return 0;
        int n=obstacleGrid[0].size();
        if (n==0) return 0;
        vector<int> dp(n);
        dp[0]=obstacleGrid[0][0]==0?1:0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (obstacleGrid[i][j]==0) {                    
                    if (j>0) dp[j]+=dp[j-1];
                } else {
                    dp[j]=0;
                }
            }
        }
        
        return dp[n-1];
    }    
};

