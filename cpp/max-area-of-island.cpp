695. Max Area of Island
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int m, int n) {
        int res=1;
        grid[row][col]=0;
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) {
                res+=dfs(grid, nr, nc, m, n);
            }
        }
        
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        int res=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) res=max(res, dfs(grid, i, j, m, n));
            }
        }
        return res;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
