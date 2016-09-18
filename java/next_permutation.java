public class Solution {
    void reverse(int[] nums, int start, int end) {
        while (start<end) {
            int tmp=nums[start];
            nums[start]=nums[end];
            nums[end]=tmp;
            start++;
            end--;
        }
    }
    
    void swap(int[] nums, int a, int b) {
        int tmp=nums[a];
        nums[a]=nums[b];
        nums[b]=tmp;
    }
    
    // 2 5 4 3 1
    public void nextPermutation(int[] nums) {
        if (nums.length==0) return;
        int i;
        for (i=nums.length-1; i>0; i--) {
            if (nums[i]>nums[i-1]) break;
        }
        if (i==0) {
            reverse(nums, 0, nums.length-1);
            return;
        }
        
        int k=i-1;
        int j;
        for (j=nums.length-1; j>=i; j--) {
            if (nums[j]>nums[k]) break;
        }
        swap(nums, k, j);
        reverse(nums, i, nums.length-1);
    }
}
