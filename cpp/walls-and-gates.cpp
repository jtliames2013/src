286. Walls and Gates
 You are given a m x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

1. DFS
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int row, int col, int m, int n) {
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            
            if (nr>=0 && nr<m && nc>=0 && nc<n && rooms[nr][nc]>rooms[row][col]) {
                rooms[nr][nc]=rooms[row][col]+1;
                dfs(rooms, nr, nc, m, n);
            }
        }    
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        if (m==0) return;
        int n=rooms[0].size();
        if (n==0) return;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (rooms[i][j]==0) {
                    dfs(rooms, i, j, m, n);
                }
            }
        }
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

2. BFS
class Solution {
public:
    void bfs(vector<vector<int>>& rooms, int row, int col, int m, int n) {
        queue<pair<int,int>> q;
        q.push({row, col});
        
        while (!q.empty()) {
            pair<int,int> f=q.front();
            q.pop();
            
            for (int k=0; k<4; k++) {
                int nr=f.first+delta[k][0];
                int nc=f.second+delta[k][1];
                
                if (nr>=0 && nr<m && nc>=0 && nc<n && rooms[nr][nc]>rooms[f.first][f.second]) {
                    rooms[nr][nc]=rooms[f.first][f.second]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        if (m==0) return;
        int n=rooms[0].size();
        if (n==0) return;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (rooms[i][j]==0) {
                    bfs(rooms, i, j, m, n);
                }
            }
        }
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

3. Optimized BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        if (m==0) return;
        int n=rooms[0].size();
        if (n==0) return;
        queue<pair<int,int>> q;
                
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (rooms[i][j]==0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            pair<int,int> f=q.front();
            q.pop();
            
            for (int k=0; k<4; k++) {
                int nr=f.first+delta[k][0];
                int nc=f.second+delta[k][1];
                
                if (nr>=0 && nr<m && nc>=0 && nc<n && rooms[nr][nc]>rooms[f.first][f.second]) {
                    rooms[nr][nc]=rooms[f.first][f.second]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

