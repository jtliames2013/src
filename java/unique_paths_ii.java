public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        int[][] dp=new int[m][n];
        if (obstacleGrid[0][0]==1) return 0;
        else dp[0][0]=1;
        
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
}

2.
public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        int[] dp=new int[n];
        if (obstacleGrid[0][0]==1) return 0;
        else dp[0]=1;
        
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
}
