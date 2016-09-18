public class Solution {
    public int majorityElement(int[] nums) {
        int n=0, count=0;
        
        for (int i=0; i<nums.length; i++) {
            if (count==0) {
                n=nums[i];
                count++;
            } else {
                if (nums[i]==n) count++;
                else count--;
            }
        }
        return n;
    }
}
