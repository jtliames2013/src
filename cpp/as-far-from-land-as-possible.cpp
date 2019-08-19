1162. As Far from Land as Possible
Medium

51

4

Favorite

Share
Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

If no land or water exists in the grid, return -1.

 

Example 1:



Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: 
The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:



Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: 
The cell (2, 2) is as far as possible from all the land with distance 4.
 

Note:

1 <= grid.length == grid[0].length <= 100
grid[i][j] is 0 or 1

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res=-1;
        int m=grid.size(), n=grid[0].size();
        queue<pair<int,int>> q;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1) q.push({i,j});
            }
        }
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                for (int k=0; k<4; ++k) {
                    int nr=f.first+delta[k][0];
                    int nc=f.second+delta[k][1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0) {
                        q.push({nr,nc});
                        grid[nr][nc]=1;
                    }
                }
            }
            res++;
        }
        return res<=0?-1:res;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
