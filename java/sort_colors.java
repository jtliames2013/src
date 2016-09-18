public class Solution {
    void swap(int[] nums, int i, int j) {
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
    
    public void sortColors(int[] nums) {
        int n=nums.length;
        if (n==0) return;
        int start=0, end=n-1;
        for (int i=0; i<=end;) {
            if (nums[i]==0) {
                swap(nums, start, i);
                start++;
                i++;
            } else if (nums[i]==2) {
                swap(nums, end, i);
                end--;
            } else {
                i++;
            }
        }
    }
}
