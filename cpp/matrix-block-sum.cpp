1314. Matrix Block Sum
Medium

40

5

Add to List

Share
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> res(m, vector<int>(n)), sum(m+1, vector<int>(n+1));
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i-1][j-1];
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                res[i][j]=sum[min(m, i+K+1)][min(n, j+K+1)]+sum[max(0, i-K)][max(0, j-K)]-sum[max(0, i-K)][min(n, j+K+1)]-sum[min(m, i+K+1)][max(0, j-K)];
            }
        }
        return res;
    }
};

