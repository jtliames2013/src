public class Solution {
    public int minPathSum(int[][] grid) {
        int m=grid.length;
        if (m==0) return 0;
        int n=grid[0].length;
        if (n==0) return 0;
        
        int[][] dp=new int[m][n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0 && j==0) dp[i][j]=grid[i][j];
                else if (i==0) dp[i][j]=dp[i][j-1]+grid[i][j];
                else if (j==0) dp[i][j]=dp[i-1][j]+grid[i][j];
                else {
                    dp[i][j]=Math.min(dp[i][j-1],dp[i-1][j])+grid[i][j];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
}

2.
public class Solution {
    public int minPathSum(int[][] grid) {
        int m=grid.length;
        if (m==0) return 0;
        int n=grid[0].length;
        if (n==0) return 0;
        
        int[] dp=new int[n];
        dp[0]=grid[0][0];
        for (int j=1; j<n; j++) {
            dp[j]=dp[j-1]+grid[0][j];
        }
        
        for (int i=1; i<m; i++) {
            dp[0]+=grid[i][0];
            for (int j=1; j<n; j++) {
                dp[j]=Math.min(dp[j-1],dp[j])+grid[i][j];
            }
        }
        
        return dp[n-1];
    }
}
