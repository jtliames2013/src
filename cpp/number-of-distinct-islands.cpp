694. Number of Distinct Islands
Medium

519

33

Favorite

Share
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.

Amazon
|
5

Apple
|
3

Facebook
|
2

    /** WARNING: DO NOT FORGET to add path for backtracking, otherwise, we may have same result when we count two 
     * distinct islands in some cases
     * 
     * eg:              1 1 1   and    1 1 0
     *                  0 1 0          0 1 1
     * with b:          rdbr           rdr
     * without b:       rdr            rdr
     * */

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int res=0, m=grid.size(), n=grid[0].size();
        unordered_set<string> st;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1) {
                    string path;
                    dfs(grid, i, j, m, n, path);
                    if (st.find(path)==st.end()) {
                        st.insert(path);
                        res++;
                    }
                }
            }
        }
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid, int row, int col, int m, int n, string& path) {
        grid[row][col]=2;        
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) {
                path+=dir[k];
                dfs(grid, nr, nc, m, n, path);
                path+='b'; // back
            }
        }
    }
    
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
    const char dir[4]={'l', 'r', 'd', 'u'};
};

