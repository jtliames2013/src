public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length==0) return 0;
        int start=1;
        for (int i=1; i<nums.length; i++) {
            if (nums[i]!=nums[i-1]) {
                if (i!=start) nums[start]=nums[i];
                start++;
            }
        }
        
        return start;
    }
}
