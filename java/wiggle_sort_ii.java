public class Solution {
    public void wiggleSort(int[] nums) {
        if (nums.length==0) return;
        int[] sorted=new int[nums.length];
        for (int i=0; i<nums.length; i++) sorted[i]=nums[i];
        Arrays.sort(sorted);
        
        int j=sorted.length-1;
        for (int i=1; i<nums.length; i+=2) {
            nums[i]=sorted[j--];
        }
        for (int i=0; i<nums.length; i+=2) {
            nums[i]=sorted[j--];
        }
    }
}
