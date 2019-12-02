803. Bricks Falling When Hit
DescriptionHintsSubmissionsDiscussSolution
We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.

We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.

Return an array representing the number of bricks that will drop after each erasure in sequence.

Example 1:
Input: 
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
Output: [2]
Explanation: 
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
Example 2:
Input: 
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: 
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.
 

Note:

The number of rows and columns in the grid will be in the range [1, 200].
The number of erasures will not exceed the area of the grid.
It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
An erasure may refer to a location with no brick - if it does, no bricks drop.


Reversely add hit bricks back. The size of the component added back in each step is the number of bricks dropped in
the original order.

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m=grid.size(), n=grid[0].size(), h=hits.size();
        vector<int> res(h);
        
        for (auto& hit:hits) grid[hit[0]][hit[1]]--;
        
        for (int j=0; j<n; ++j) {
            if (grid[0][j]==1) dfs(grid, 0, j, m, n);
        }
        
        for (int i=h-1; i>=0; --i) {
            grid[hits[i][0]][hits[i][1]]++;
            if (grid[hits[i][0]][hits[i][1]]==1 && 
                isConnected(grid, hits[i][0], hits[i][1], m, n)) {
                res[i]=dfs(grid, hits[i][0], hits[i][1], m, n)-1;
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col, int m, int n) {
        int res=1;
        grid[row][col]=2;
        
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) {
                res+=dfs(grid, nr, nc, m, n);
            }
        }
        return res;
    }
    
    bool isConnected(vector<vector<int>>& grid, int row, int col, int m, int n) {
        if (row==0) return true;
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==2) return true;    
        }
        return false;
    }
    
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

