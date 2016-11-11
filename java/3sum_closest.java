public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int closest=0, mindiff=Integer.MAX_VALUE;
        int n=nums.length;
        if (n==0) return 0;
        Arrays.sort(nums);
        
        for (int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            while (l<r) {
                int sum=nums[i]+nums[l]+nums[r];
                if (mindiff>Math.abs(sum-target)) {
                    mindiff=Math.abs(sum-target);
                    closest=sum;
                }
                if (sum==target) return sum;
                else if (sum<target) l++;
                else r--;
            }
        }
        return closest;
    }
}
