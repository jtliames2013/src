public class Solution {
    public int coinChange(int[] coins, int amount) {
        int n=coins.length;
        if (n==0) return 0;
        if (amount==0) return 0;
        
        int[] dp=new int[amount+1];
        for (int i=1; i<dp.length; i++) dp[i]=-1;
        
        for (int i=1; i<dp.length; i++) {
            for (int j=0; j<coins.length; j++) {
                if (i-coins[j]>=0 && dp[i-coins[j]]>=0) {
                    if (dp[i]==-1 || dp[i]>dp[i-coins[j]]+1) {
                        dp[i]=dp[i-coins[j]]+1;
                    }
                }
            }
        }
        
        return dp[amount];
    }
}
