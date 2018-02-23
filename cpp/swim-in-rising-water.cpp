778. Swim in Rising Water
DescriptionHintsSubmissionsDiscussSolution
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:

2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].

1.
class Solution {
public:
    struct Point {
        int row;
        int col;
        int elev;
        Point(int r, int c, int e): row(r), col(c), elev(e) {}
    };
    
    int swimInWater(vector<vector<int>>& grid) {        
        int n=grid.size();
        int res=max(grid[0][0], grid[n-1][n-1]);
        auto comp=[](Point& a, Point& b) { return a.elev>b.elev; };
        priority_queue<Point, vector<Point>, decltype(comp)> pq(comp);
        vector<vector<bool>> visited(n, vector<bool>(n));
        pq.push(Point(0, 0, res));
        visited[0][0]=true;
        
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            res=max(res, t.elev);            
            
            for (int k=0; k<4; k++) {
                int nr=t.row+delta[k][0];
                int nc=t.col+delta[k][1];
                if (nr>=0 && nr<n && nc>=0 && nc<n && visited[nr][nc]==false) {
                    if (nr==n-1 && nc==n-1) return res;
                    pq.push(Point(nr, nc, grid[nr][nc]));
                    visited[nr][nc]=true;
                }
            }
        }
        return -1;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

2. optimization with BFS
class Solution {
public:
    struct Point {
        int row;
        int col;
        int elev;
        Point(int r, int c, int e): row(r), col(c), elev(e) {}
    };
    
    int swimInWater(vector<vector<int>>& grid) {        
        int n=grid.size();
        int res=max(grid[0][0], grid[n-1][n-1]);
        auto comp=[](Point& a, Point& b) { return a.elev>b.elev; };
        priority_queue<Point, vector<Point>, decltype(comp)> pq(comp);
        vector<vector<bool>> visited(n, vector<bool>(n));
        pq.push(Point(0, 0, res));
        visited[0][0]=true;
        
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            res=max(res, t.elev);            
        
            queue<Point> q;
            q.push(t);            
            while (!q.empty()) {
                // minimize the number of elements in pq
                auto f=q.front();
                q.pop();
                if (f.row==n-1 && f.col==n-1) return res;
                for (int k=0; k<4; k++) {
                    int nr=f.row+delta[k][0];
                    int nc=f.col+delta[k][1];
                    if (nr>=0 && nr<n && nc>=0 && nc<n && visited[nr][nc]==false) {
                        if (grid[nr][nc]<=res) q.push(Point(nr, nc, grid[nr][nc]));
                        else pq.push(Point(nr, nc, grid[nr][nc]));
                        visited[nr][nc]=true;
                    }
                }                
            }
        }
        return -1;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
