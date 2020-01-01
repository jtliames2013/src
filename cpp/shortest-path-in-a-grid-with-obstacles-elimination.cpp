1293. Shortest Path in a Grid with Obstacles Elimination
Hard

154

1

Add to List

Share
Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 

Example 2:

Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0

Google
|
LeetCode

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        int  m=grid.size(), n=grid[0].size(), res=0;
        // minimal number of obstacles to visit a position
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        q.push({0, 0, 0});
        visited[0][0]=0;
        if (m==1 && n==1) return 0;
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                int row=f[0], col=f[1], obstacles=f[2];
                
                for (int k=0; k<4; ++k) {
                    int nr=row+delta[k][0];
                    int nc=col+delta[k][1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n) {                    
                        int no=obstacles+grid[nr][nc];
                        if (no<visited[nr][nc] && no<=K) {
                            if (nr==m-1 && nc==n-1) return res+1;
                            q.push({nr, nc, no});
                            visited[nr][nc]=no;
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

