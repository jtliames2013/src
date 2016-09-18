public class Solution {
    void getSubsets(int[] nums, List<List<Integer>> res, List<Integer> set, int start) {
        res.add(new ArrayList<Integer>(set));
        
        for (int i=start; i<nums.length; i++) {
            if (i==start||nums[i]!=nums[i-1]) {
                set.add(nums[i]);
                getSubsets(nums, res, set, i+1);
                set.remove(set.size()-1);
            }
        }
    }
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        if (nums.length==0) return res;
        Arrays.sort(nums);
        List<Integer> set=new ArrayList<>();
        getSubsets(nums, res, set, 0);
        
        return res;
    }
}
