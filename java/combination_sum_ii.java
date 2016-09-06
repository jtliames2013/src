public class Solution {
    void getSum(List<List<Integer>> res, List<Integer> nums, List<Integer> comb, int target, int start) {
        if (target==0) {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        
        for (int i=start; i<nums.size(); i++) {
            if (target-nums.get(i)>=0 && (i==start || nums.get(i)!=nums.get(i-1))) {
                comb.add(nums.get(i));
                getSum(res, nums, comb, target-nums.get(i), i+1);
                comb.remove(comb.size()-1);
            }
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        List<Integer> comb=new ArrayList<Integer>();
        int n=candidates.length;
        if (n==0) return res;
        List<Integer> nums=new ArrayList<Integer>();
        for (int i:candidates) nums.add(i);
        Collections.sort(nums);
        
        getSum(res, nums, comb, target, 0);
        
        return res;
    }
}
