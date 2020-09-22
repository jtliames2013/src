1594. Maximum Non Negative Product in a Matrix
Medium

118

5

Add to List

Share
You are given a rows x cols matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (rows - 1, cols - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative return -1.

Notice that the modulo is performed after getting the maximum product.

 

Example 1:

Input: grid = [[-1,-2,-3],
               [-2,-3,-3],
               [-3,-3,-2]]
Output: -1
Explanation: It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
Example 2:

Input: grid = [[1,-2,1],
               [1,-2,1],
               [3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is in bold (1 * 1 * -2 * -4 * 1 = 8).
Example 3:

Input: grid = [[1, 3],
               [0,-4]]
Output: 0
Explanation: Maximum non-negative product is in bold (1 * 0 * -4 = 0).
Example 4:

Input: grid = [[ 1, 4,4,0],
               [-2, 0,0,1],
               [ 1,-1,1,1]]
Output: 2
Explanation: Maximum non-negative product is in bold (1 * -2 * 1 * -1 * 1 * 1 = 2).
 

Constraints:

1 <= rows, cols <= 15
-4 <= grid[i][j] <= 4

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<long>>> dp(m, vector<vector<long>>(n, vector<long>(2)));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j==0) {
                    dp[i][j][0]=dp[i][j][1]=grid[i][j];
                } else if (i==0) {
                    dp[i][j][0]=dp[i][j][1]=dp[i][j-1][0]*grid[i][j];
                } else if (j==0) {
                    dp[i][j][0]=dp[i][j][1]=dp[i-1][j][0]*grid[i][j];
                } else {
                    long mx=max(dp[i-1][j][0], dp[i][j-1][0])*grid[i][j];
                    long mn=min(dp[i-1][j][1], dp[i][j-1][1])*grid[i][j];
                    dp[i][j][0]=max(mx, mn);
                    dp[i][j][1]=min(mx, mn);
                }
            }
        }
        
        if (dp[m-1][n-1][0]>=0) return dp[m-1][n-1][0]%mod;
        return -1;
    }
private:
    const int mod=1e9+7;
};

