public class Solution {
    public void gameOfLife(int[][] board) {
        int m=board.length;
        if (m==0) return;
        int n=board[0].length;
        if (n==0) return;
        
        int[][] delta={{-1,-1},{-1,0}, {-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int count=0;
                for (int k=0; k<8; k++) {
                    int nr=i+delta[k][0];
                    int nc=j+delta[k][1];
                    
                    if (nr>=0&&nr<m&&nc>=0&&nc<n) {
                        if ((board[nr][nc] & 0x1)==1) count++;
                        if (count>3) break;
                    }
                }
                
                if ((board[i][j] & 0x1)==1) {
                    if (count>=2 && count<=3) {
                        board[i][j]|=0x2;
                    }
                } else {
                    if (count==3) {
                        board[i][j]|=0x2;
                    }
                }
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
}
