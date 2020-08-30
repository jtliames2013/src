1568. Minimum Number of Days to Disconnect Island
Medium

72

50

Add to List

Share
Given a 2D grid consisting of 1s (land) and 0s (water).  An island is a maximal 4-directionally (horizontal or vertical) connected group of 1s.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 

Example 1:



Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:

Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
Example 3:

Input: grid = [[1,0,1,0]]
Output: 0
Example 4:

Input: grid = [[1,1,0,1,1],
               [1,1,1,1,1],
               [1,1,0,1,1],
               [1,1,0,1,1]]
Output: 1
Example 5:

Input: grid = [[1,1,0,1,1],
               [1,1,1,1,1],
               [1,1,0,1,1],
               [1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[i].length <= 30
grid[i][j] is 0 or 1.

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if (count(grid, m, n)!=1) return 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1) {
                    grid[i][j]=0;
                    if (count(grid, m, n)!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
private:
    int count(vector<vector<int>>& grid, int m, int n) {
        int res=0;
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1 && visited[i][j]==0) {
                    dfs(grid, visited, i, j, m, n);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col, int m, int n) {
        if (row<0 || row>=m || col<0 || col>=n) return;
        if (grid[row][col]==0 || visited[row][col]==1) return;
        visited[row][col]=1;
        dfs(grid, visited, row-1, col, m, n);
        dfs(grid, visited, row+1, col, m, n);
        dfs(grid, visited, row, col-1, m, n);
        dfs(grid, visited, row, col+1, m, n);
    }
};
