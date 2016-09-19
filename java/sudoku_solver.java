public class Solution {
    int N;
    Solution() {
        N=9;
    }
    
    boolean isValid(char[][] board, int row, int col) {
        for (int c=0; c<N; c++) {
            if (c!=col && board[row][c]==board[row][col]) return false;
        }
        
        for (int r=0; r<N; r++) {
            if (r!=row && board[r][col]==board[row][col]) return false;
        }
        
        int br=row/3;
        int bc=col/3;
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int r=br*3+i;
                int c=bc*3+j;
                if ((r!=row||c!=col) && board[r][c]==board[row][col]) return false;
            }
        }
        
        return true;
    }
    
    boolean solveSudoku(char[][] board, int row, int col) {
        if (row==N) return true;
        
        int nextRow, nextCol;
        if (col<N-1) {
            nextRow=row;
            nextCol=col+1;
        } else {
            nextRow=row+1;
            nextCol=0;
        }
        
        if (board[row][col]=='.') {
            for (int i=0; i<N; i++) {
                board[row][col]=(char)(i+'1');
                if (isValid(board, row, col)) {
                    if (solveSudoku(board, nextRow, nextCol)) return true;
                }
                
                board[row][col]='.';
            }
        } else {
            return solveSudoku(board, nextRow, nextCol);
        }
        
        return false;
    }
    
    public void solveSudoku(char[][] board) {
        if (board.length!=N || board[0].length!=N) return;
        solveSudoku(board, 0, 0);    
    }
}
