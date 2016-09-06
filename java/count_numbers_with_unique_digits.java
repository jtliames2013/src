public class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n>10) return 0;
        int[] dp=new int[n];
        dp[0]=10;
        for (int i=1; i<n; i++) {
            if (i==1) dp[i]=9*9;
            else dp[i]=dp[i-1]*(10-i);
        }
        
        int res=0;
        for (int i=0; i<n; i++) res+=dp[i];
        return res;
    }
}
