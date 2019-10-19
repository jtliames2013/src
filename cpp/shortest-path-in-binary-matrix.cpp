1091. Shortest Path in Binary Matrix
Medium

143

24

Favorite

Share
In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res=0, n=grid.size();
        if (n==0) return 0;
        if (n==1) return grid[0][0]==0?1:-1;
        if (grid[0][0]==1) return -1;        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        
        while (!q.empty()) {
            res++;
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                
                for (int k=0; k<8; ++k) {
                    int nr=f.first+delta[k][0];
                    int nc=f.second+delta[k][1];
                    if (nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0) {
                        if (nr==n-1 && nc==n-1) return res+1;
                        q.push({nr, nc});
                        grid[nr][nc]=1;
                    }
                }
            }            
        }
        
        return -1;
    }
private:
      const int delta[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
};
