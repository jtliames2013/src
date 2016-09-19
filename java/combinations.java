public class Solution {
    void getComb(List<List<Integer>> res, List<Integer> comb, int n, int k, int start) {
        if (comb.size()==k) {
            res.add(new ArrayList<Integer>(comb));
            return;
        }
        
        if (n-start+1+comb.size()<k) return;
        
        for (int i=start; i<=n; i++) {
            comb.add(i);
            getComb(res, comb, n, k, i+1);
            comb.remove(comb.size()-1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        List<Integer> comb=new ArrayList<>();
        getComb(res, comb, n, k, 1);
        
        return res;
    }
}
