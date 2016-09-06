public class Solution {
    void getSum(List<List<Integer>> res, int[] candidates, List<Integer> comb, int target, int start) {
        if (target==0) {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        
        for (int i=start; i<candidates.length; i++) {
            if (target-candidates[i]>=0) {
                comb.add(candidates[i]);
                getSum(res, candidates, comb, target-candidates[i], i);
                comb.remove(comb.size()-1);
            }
        }
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        List<Integer> comb=new ArrayList<Integer>();
        int n=candidates.length;
        if (n==0) return res;
        
        getSum(res, candidates, comb, target, 0);
        
        return res;
    }
}
