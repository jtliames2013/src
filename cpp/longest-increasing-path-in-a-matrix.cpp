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
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        int res=0;
        vector<vector<int>> dp(m, vector<int>(n));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                res=max(res, dfs(matrix, dp, i, j, m, n));
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col, int m, int n) {
        if (dp[row][col]>0) return dp[row][col];

        dp[row][col]=1;
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[row][col]) {
                dp[row][col]=max(dp[row][col], dfs(matrix, dp, nr, nc, m, n)+1);
            }
        }
        return dp[row][col];
    }

    const int delta[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
};
