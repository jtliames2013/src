1463. Cherry Pickup II
Hard

65

3

Add to List

Share
Given a rows x cols matrix grid representing a field of cherries. Each cell in grid represents the number of cherries that you can collect.

You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located at the top-right corner (0, cols-1) of the grid.

Return the maximum number of cherries collection using both robots  by following the rules below:

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
When both robots stay on the same cell, only one of them takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in the grid.
 

Example 1:



Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
Example 2:



Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
Example 3:

Input: grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
Output: 22
Example 4:

Input: grid = [[1,1],[1,1]]
Output: 4
 

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100 

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(grid, dp, 0, 0, n-1);
    }
private:
    int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int row, int col1, int col2) {
        int m=grid.size(), n=grid[0].size(), res=0;
        if (row==m) return 0;
        if (dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        for (int i=-1; i<=1; ++i) {
            for (int j=-1; j<=1; ++j) {
                int nc1=col1+i, nc2=col2+j;
                if (nc1>=0 && nc1<n && nc2>=0 && nc2<n) {
                    res=max(res, dfs(grid, dp, row+1, nc1, nc2));
                }
            }
        }

        res+=col1==col2?grid[row][col1]:grid[row][col1]+grid[row][col2];
        dp[row][col1][col2]=res;
        return dp[row][col1][col2];
    }
};

