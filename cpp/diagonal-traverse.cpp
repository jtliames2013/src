498. Diagonal Traverse Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 6398
Total Submissions: 13830
Difficulty: Medium
Contributors:
nberserk
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if (m==0) return res;
        int n=matrix[0].size();
        if (n==0) return res;
        
        res.resize(m*n);
        int row=0, col=0;
        
        for (int i=0; i<m*n; i++) {
            res[i]=matrix[row][col];
            
            if ((row+col)%2==0) {
                // moving up
                if (col==n-1) row++; // handle this first since row will not be out of bound
                else if (row==0) col++;
                else { row--; col++; }
            } else {
                // moving down
                if (row==m-1) col++; // handle this first since col will not be out of bound
                else if (col==0) row++;
                else { row++; col--; }
            }
        }
        
        return res;
    }
};

