public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res=new int[]{-1,-1};
        int n=nums.length;
        if (n==0) return res;
        int l=0, r=n-1, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            if (nums[mid]<target) l=mid+1;
            else r=mid;
        }
        if (nums[l]!=target) return res;
        else res[0]=l;
        
        r=n-1;
        while (l<r) {
            mid=l+(r-l)/2+1;
            if (nums[mid]>target) r=mid-1;
            else l=mid;
        }
        res[1]=r;
        
        return res;
    }
}
