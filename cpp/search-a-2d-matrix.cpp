74. Search a 2D Matrix 
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

Hide Tags Array Binary Search
Hide Similar Problems (M) Search a 2D Matrix II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if (m==0) return false;
        int n=matrix[0].size();
        if (n==0) return false;
        
        int l=0, r=m-1, mid;
        while (l<=r) {
            mid=l+(r-l)/2;
            if (matrix[mid][n-1]==target) return true;
            else if (matrix[mid][n-1]<target) l=mid+1;
            else r=mid-1;
        }
        if (l==m) return false;
        int row=l;
        l=0;
        r=n-1;
        while (l<=r) {
            mid=l+(r-l)/2;
            if (matrix[row][mid]==target) return true;
            else if (matrix[row][mid]<target) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};

