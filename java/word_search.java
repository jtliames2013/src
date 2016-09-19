public class Solution {
    boolean exist(char[][] board, boolean[][] visited, int row, int col, int m, int n, String word, int start) {
        if (start<word.length() && board[row][col]!=word.charAt(start)) return false;
        start++;
        if (start>=word.length()) return true;
        int[][] delta=new int[][]{{-1,0},{1,0},{0,-1},{0,1}};
        visited[row][col]=true;
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            
            if (nr>=0&&nr<m&&nc>=0&&nc<n&&visited[nr][nc]==false) {
                if (exist(board, visited, nr, nc, m, n, word, start)) return true;
            }
        }
        
        visited[row][col]=false;
        return false;
    }
    
    public boolean exist(char[][] board, String word) {
        int m=board.length;
        if (m==0) return false;
        int n=board[0].length;
        if (n==0) return false;
        boolean[][] visited=new boolean[m][n];
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (exist(board, visited, i, j, m, n, word, 0)) return true;
            }
        }
        return false;
    }
}
