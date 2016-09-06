public class Solution {
    void dfs(List<Integer> res, int n, int curr) {
        if (curr>n) {
            return;
        }    
        res.add(curr);
        for (int i=0; i<=9; i++) {
            dfs(res, n, curr*10+i);
        }
    }
    
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res=new ArrayList<Integer>();
        for (int i=1; i<=9; i++) {
            dfs(res, n, i);
        }
        
        return res;
    }
}
