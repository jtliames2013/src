827. Making A Large Island
Hard

313

10

Favorite

Share
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Notes:

1 <= grid.length = grid[0].length <= 50.
0 <= grid[i][j] <= 1.

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int res=0, m=grid.size(), n=grid[0].size(), index=2;        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1) {
                    areas[index]=dfs(grid, i, j, m, n, index);
                    res=max(res, areas[index++]);
                }                
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==0) {                                        
                    auto indices=getNeighborIndex(grid, i, j, m, n);
                    int area=1;
                    for (auto& i:indices) area+=areas[i];                    
                    res=max(res, area);
                }
            }
        }
        
        return res;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col, int m, int n, int index) {
        int res=1;
        grid[row][col]=index;
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) {
                res+=dfs(grid, nr, nc, m, n, index);
            }
        }
        
        return res;
    }
    
    unordered_set<int> getNeighborIndex(vector<vector<int>>& grid, int row, int col, int m, int n) {
        unordered_set<int> st;
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>1) {
                st.insert(grid[nr][nc]);
            }
        }
        return st;
    }
    
    unordered_map<int,int> areas;
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

