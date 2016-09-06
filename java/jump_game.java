public class Solution {
    public boolean canJump(int[] nums) {
        int index=0, reach=0;
        
        while (true) {
            if (index>=nums.length || index>reach) break;
            reach=Math.max(reach, index+nums[index]);
            index++;
        }
        
        if (reach>=nums.length-1) return true;
        else return false;
    }
}
