public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int minlen=Integer.MAX_VALUE;
        int sum=0;
        int l, r;
        
        for (l=0, r=0; r<nums.length;) {
            sum+=nums[r];
            r++;
            
            while (sum>=s) {
                minlen=Math.min(minlen, r-l);
                sum-=nums[l];
                l++;                
            }
        }
        
        if (minlen==Integer.MAX_VALUE) return 0;
        else return minlen;
    }
}
