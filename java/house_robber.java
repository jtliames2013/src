public class Solution {
    public int rob(int[] nums) {
        int n=nums.length;
        if (n==0) return 0;
        int[] dp=new int[n+1];
        dp[1]=nums[0];
        for (int i=2; i<=n; i++) {
            dp[i]=Math.max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        
        return dp[n];
    }
}

2. get house list
public class Solution {
    public int rob(int[] nums) {
        int n=nums.length;
        if (n==0) return 0;
        int[] dp=new int[n+1];
        int[] pos=new int[n+1];
        dp[1]=nums[0];
        for (int i=2; i<=n; i++) {
            if (dp[i-1]>dp[i-2]+nums[i-1]) {
                dp[i]=dp[i-1];
                pos[i]=i-1;
            } else {
                dp[i]=dp[i-2]+nums[i-1];
                pos[i]=i-2;
            }
        }
        
        List<Integer> res=new ArrayList<>();
        int i;
        for (i=n; i>=2;) {
            if (pos[i]==i-2) {
                res.add(i);
            }
            i=pos[i];
        }
        if (i==1) res.add(i);
        
        return dp[n];
    }
}
