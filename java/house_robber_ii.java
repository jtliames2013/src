public class Solution {
    int roblinear(int[] nums, int start, int end) {
        int odd=0, even=0;
        for (int i=start; i<=end; i++) {
            if (i%2==0) {
                even=Math.max(odd, even+nums[i]);
            } else {
                odd=Math.max(even, odd+nums[i]);
            }
        }
        return Math.max(odd, even);
    }
    
    public int rob(int[] nums) {
        int n=nums.length;
        if (n==0) return 0;
        if (n==1) return nums[0];
        return Math.max(roblinear(nums, 0, n-2), roblinear(nums, 1, n-1));
    }
}
