public class Solution {
    String getString(int[] nums, int start, int end) {
        if (start==end-1) {
            return Integer.toString(nums[start]);
        } else {
            return Integer.toString(nums[start]) + "->" + Integer.toString(nums[end-1]);
        }
    }
    public List<String> summaryRanges(int[] nums) {
        List<String> res=new ArrayList<String>();
        if (nums.length==0) return res;
        
        int start=0;
        int i;
        for (i=1; i<nums.length; i++) {
            if (nums[i]>nums[i-1]+1) {
                res.add(getString(nums, start, i));
                start=i;
            }
        }
        
        res.add(getString(nums, start, i));
        return res;
    }
}
