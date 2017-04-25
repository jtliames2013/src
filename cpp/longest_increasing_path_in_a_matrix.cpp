329. Longest Increasing Path in a Matrix
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4

The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Depth-first Search Topological Sort Memoization

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col, int m, int n) {
        if (dp[row][col]>0) return dp[row][col];
        
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && matrix[row][col]<matrix[nr][nc]) {
                dp[row][col]=max(dp[row][col], longestIncreasingPath(matrix, dp, nr, nc, m, n));
            }
        }
        dp[row][col]++;
        return dp[row][col];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        int len=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                len=max(len, longestIncreasingPath(matrix, dp, i, j, m, n));
            }
        }
        return len;
    }
private:
    const int delta[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
};

