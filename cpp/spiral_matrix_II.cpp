59. Spiral Matrix II  QuestionEditorial Solution  My Submissions
Total Accepted: 56680
Total Submissions: 158341
Difficulty: Medium
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
Hide Tags Array
Hide Similar Problems (M) Spiral Matrix

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n==0) return vector<vector<int>>();
        vector<vector<int>> res(n, vector<int>(n,0));
        int num=1;
        for (int i=0; i<(n+1)/2; i++) {
            // top
            for (int j=i; j<n-i; j++) res[i][j]=num++;
            // right
            for (int j=i+1; j<n-i; j++) res[j][n-i-1]=num++;
            // bottom
            for (int j=n-i-2; j>=i; j--) res[n-i-1][j]=num++;
            // left
            for (int j=n-i-2; j>i; j--) res[j][i]=num++;
        }
        
        return res;
    }
};

