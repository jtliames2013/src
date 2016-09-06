public class Solution {
    void getComb(List<List<Integer>> res, List<Integer> comb, int k, int n, int digit) {
        if (k==0 && n==0) {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        
        for (int i=digit; i<=9; i++) {
            if (k>0 && n-i>=0) {
                comb.add(i);
                getComb(res, comb, k-1, n-i, i+1);
                comb.remove(comb.size()-1);
            }
        }
    }
    
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        List<Integer> comb=new ArrayList<Integer>();
        getComb(res, comb, k, n, 1);
        
        return res;
    }
}
