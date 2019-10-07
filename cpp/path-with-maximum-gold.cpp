1219. Path with Maximum Gold
Medium

56

2

Favorite

Share
In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

1 <= grid.length, grid[i].length <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res=0, m=grid.size(), n=grid[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]!=0) res=max(res, dfs(grid, m, n, i, j));
            }
        }
        
        return res;
    }
private:
    int dfs(vector<vector<int>>& grid, int m, int n, int row, int col) {
        int res=0, val=grid[row][col];
        grid[row][col]=0;
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=0) {
                res=max(res, dfs(grid, m, n, nr, nc));
            }
        }
        
        grid[row][col]=val;
        return res+val;
    }
    
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
