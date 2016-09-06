public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m=matrix.length;
        if (m==0) return false;
        int n=matrix[0].length;
        if (n==0) return false;
        
        int row=0, col=n-1;
        while (row<m && col>=0) {
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) col--;
            else row++;
        }
        
        return false;
    }
}
