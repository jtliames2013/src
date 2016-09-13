public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Integer> set=new TreeSet<Integer>();
        for (int i=0; i<nums.length; i++) {
            Integer l=set.ceiling(nums[i]-t);
            if (l!=null && Math.abs(l-nums[i])<=t) return true;
            set.add(nums[i]);
            if (set.size()>k) set.remove(nums[i-k]);
        }
        
        return false;
    }
}
