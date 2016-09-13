public class Solution {
    List<String> getBoard(int[] pos, int n) {
        List<String> res=new ArrayList<String>();
        for (int i=0; i<n; i++) {
            StringBuilder sb=new StringBuilder();
            for (int j=0; j<n; j++) {
                if (j!=pos[i]) {
                    sb.append('.');
                } else {
                    sb.append('Q');
                }
            }
            res.add(sb.toString());
        }
        
        return res;
    }
    
    boolean isValid(int[] pos, int start, int col) {
        for (int i=0; i<start; i++) {
            if (pos[i]==col || Math.abs(pos[i]-col)==Math.abs(start-i)) {
                return false;
            }
        }
        return true;
    }
    
    void solveNQueens(List<List<String>> res, int[] pos, int n, int start) {
        if (start==n) {
            res.add(getBoard(pos, n));
            return;
        }    
        
        for (int col=0; col<n; col++) {
            if (isValid(pos, start, col)) {
                pos[start]=col;
                solveNQueens(res, pos, n, start+1);
            }
        }
    }
    
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res=new ArrayList<List<String>>();
        if (n==0) return res;
        int[] pos=new int[n];
        solveNQueens(res, pos, n, 0);
        return res;
    }
}
