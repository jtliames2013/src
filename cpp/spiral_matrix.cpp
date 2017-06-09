54. Spiral Matrix  QuestionEditorial Solution  My Submissions
Total Accepted: 64092
Total Submissions: 277594
Difficulty: Medium
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

Hide Company Tags Microsoft Google Uber
Hide Tags Array
Hide Similar Problems (M) Spiral Matrix II

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if (m==0) return res;
        int n=matrix[0].size();
        if (n==0) return res;

        for (int i=0, j=0; i<(m+1)/2 && j<(n+1)/2; i++, j++) {
            // top
            for (int k=j; k<n-j; k++) res.push_back(matrix[i][k]);
            // right
            for (int k=i+1; k<m-i; k++) res.push_back(matrix[k][n-j-1]);
            // bottom
            if (m-i-1>i) {
                for (int k=n-j-2; k>=j; k--) res.push_back(matrix[m-i-1][k]);
            }
            // left
            if (n-j-1>j) {
                for (int k=m-i-2; k>i; k--) res.push_back(matrix[k][j]);
            }
        }   
        return res;
    }
};

2.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if (m==0) return res;
        int n=matrix[0].size();
        if (n==0) return res;
        int rb=0, re=m-1, cb=0, ce=n-1;
        while (rb<=re && cb<=ce) {
            for (int i=cb; i<=ce; i++) res.push_back(matrix[rb][i]);
            rb++;
            for (int i=rb; i<=re; i++) res.push_back(matrix[i][ce]);
            ce--;
            if (rb<=re) {
                for (int i=ce; i>=cb; i--) res.push_back(matrix[re][i]);
                re--;
            }
            if (cb<=ce) {
                for (int i=re; i>=rb; i--) res.push_back(matrix[i][cb]);
                cb++;
            }
        }
        
        return res;
    }
};

