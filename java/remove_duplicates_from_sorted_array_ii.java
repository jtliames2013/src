public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length<=2) return nums.length;
        int end=2;
        for (int i=2; i<nums.length; i++) {
            if (nums[i]!=nums[i-1] || nums[i]!=nums[i-2] || nums[end-1]!=nums[end-2]) {
                nums[end++]=nums[i];
            }
        }
        return end;
    }
}
