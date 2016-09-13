public class Solution {
    int sum;
    
    boolean isValid(int[] pos, int n, int start, int col) {
        for (int j=0; j<start; j++) {
            if (pos[j]==col || Math.abs(start-j)==Math.abs(col-pos[j])) {
                return false;
            }
        }
        return true;
    }
    
    void getSum(int[] pos, int n, int start) {
        if (start==n) {
            sum++;
            return;
        }
        
        for (int col=0; col<n; col++) {
            if (isValid(pos, n, start, col)){
                pos[start]=col;
                getSum(pos, n, start+1);
            }
        }
    }
    
    public int totalNQueens(int n) {
        sum=0;
        if (n<=0) return 0;
        int[] pos=new int[n];
        getSum(pos, n, 0);
        return sum;
    }
}
