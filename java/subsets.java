public class Solution {
    void getSubsets(int[] nums, List<List<Integer>> res, List<Integer> set, int start) {
        res.add(new ArrayList<Integer>(set));
        
        for (int i=start; i<nums.length; i++) {
            set.add(nums[i]);
            getSubsets(nums, res, set, i+1);
            set.remove(set.size()-1);
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        List<Integer> set=new ArrayList<Integer>();
        getSubsets(nums, res, set, 0);
        
        return res;
    }
}
