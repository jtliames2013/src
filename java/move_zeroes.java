public class Solution {
    void swap(int[] nums, int i, int j) {
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
    
    public void moveZeroes(int[] nums) {
        for (int nonzero=0, i=0; i<nums.length; i++) {
            if (nums[i]!=0) {
                if (i!=nonzero) {
                    swap(nums, nonzero, i);
                }
                nonzero++;
            }
        }
    }
}
