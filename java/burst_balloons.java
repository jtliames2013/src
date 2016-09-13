public class Solution {
    public int maxCoins(int[] nums) {
        int n=nums.length;
        if (n==0) return 0;
        int[] numbers=new int[n+2];
        System.arraycopy(nums, 0, numbers, 1, n);
        numbers[0]=1;
        numbers[n+1]=1;
        int[][] dp=new int[n+2][n+2];
        
        for (int len=1; len<=n; len++) {
            for (int l=1; l+len-1<=n; l++) {
                int r=l+len-1;
                for (int k=l; k<=r; k++) {
                    int localmax=numbers[l-1]*numbers[k]*numbers[r+1]+dp[l][k-1]+dp[k+1][r];
                    dp[l][r]=Math.max(dp[l][r], localmax);
                }
            }
        }
        return dp[1][n];
    }
}
