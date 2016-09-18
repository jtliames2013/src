public class Solution {
    public int removeElement(int[] nums, int val) {
        int end=0;
        for (int i=0; i<nums.length; i++) {
            if (nums[i]!=val) {
                if (i!=end) {
                    nums[end]=nums[i];
                }
                end++;
            }
        }
        return end;
    }
}
