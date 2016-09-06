public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res=new int[]{-1,-1};
        int n=nums.length;
        if (n==0) return res;
        int l=0, r=n-1;
        while (l<=r) {
            int mid=l+(r-l)/2;
            if (nums[mid]==target) {
                int left=mid, right=mid;
                while (left>=0 && nums[left]==target) left--;
                while (right<n && nums[right]==target) right++;
                return new int[]{left+1,right-1};
            }  else if (nums[mid]>target) {
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res;
    }
}
