766. Toeplitz Matrix
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].

1.
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0) return false;
        int n=matrix[0].size();
        if (n==0) return false;
        
        for (int i=0; i<m-1; i++) {
            for (int j=0; j<n-1; j++) {
                if (matrix[i][j]!=matrix[i+1][j+1]) return false;
            }
        }
        
        return true;
    }
};

2. scan diagonally
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0) return false;
        int n=matrix[0].size();
        if (n==0) return false;
        
        for (int i=0; i<m; i++) {
            int row=i, col=0, val=matrix[row][col];
            while (row<m && col<n) {
                if (matrix[row++][col++]!=val) return false;
            }
        }
        
        for (int j=1; j<n; j++) {
            int row=0, col=j, val=matrix[row][col];
            while (row<m && col<n) {
                if (matrix[row++][col++]!=val) return false;
            }
        }
        
        return true;
    }
};
