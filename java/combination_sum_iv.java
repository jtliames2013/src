public class Solution {
    Map<Integer,Integer> count=new HashMap<Integer,Integer>();
    public int combinationSum4(int[] nums, int target) {
        int res=0;
        if (nums==null||nums.length==0||target<0) return 0;
        if (target==0) return 1;
        if (count.containsKey(target)) return count.get(target);
        
        for (int i:nums) {
            res+=combinationSum4(nums, target-i);
        }
        
        count.put(target, res);
        return res;
    }
}
