1254. Number of Closed Islands
Medium

108

5

Favorite

Share
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 || i==m-1 || j==0 || j==n-1) {
                    if (grid[i][j]==0) dfs(grid, i, j, m, n);
                }
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==0) {
                    dfs(grid, i, j, m, n);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid, int row, int col, int m, int n) {
        grid[row][col]=1;
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0) {
                dfs(grid, nr, nc, m, n);
            }
        }
    }
    
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};    
};

