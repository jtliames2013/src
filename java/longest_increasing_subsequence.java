public class Solution {
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        if (n==0) return 0;
        int[] dp=new int[n+1];
        
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                if (j==0||nums[i-1]>nums[j-1]) {
                    dp[i]=Math.max(dp[i], dp[j]+1);
                }
            }
        }
        
        int res=0;
        for (int i=1; i<=n; i++) res=Math.max(res, dp[i]);
        return res;
    }
}

2. binary search
public class Solution {
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        if (n==0) return 0;
        List<Integer> sorted=new ArrayList<Integer>();
        for (int i=0; i<n; i++) {
            int l=0, r=sorted.size()-1;
            while (l<=r) {
                int mid=l+(r-l)/2;
                if (sorted.get(mid)<nums[i]) l=mid+1;
                else r=mid-1;
            }
            
            if (l>=sorted.size()) sorted.add(nums[i]);
            else sorted.set(l, nums[i]);
        }
        
        return sorted.size();
    }
}
