749. Contain Virus
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.

Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.

Example 1:
Input: grid = 
[[0,1,0,0,0,0,0,1],
 [0,1,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,0]]
Output: 10
Explanation:
There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

[[0,1,0,0,0,0,1,1],
 [0,1,0,0,0,0,1,1],
 [0,0,0,0,0,0,1,1],
 [0,0,0,0,0,0,0,1]]

On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
Example 2:
Input: grid = 
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.
Example 3:
Input: grid = 
[[1,1,1,0,0,0,0,0,0],
 [1,0,1,0,1,1,1,1,1],
 [1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.
Note:
The number of rows and columns of grid will each be in the range [1, 50].
Each grid[i][j] will be either 0 or 1.
Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next round.

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        int res=0;
        while (1) {
            int walls=install(grid, m, n);
            if (walls==0) break;
            res+=walls;
        }
        return res;
    }
private:
    int install(vector<vector<int>>& grid, int m, int n) {
        int maxWalls=0, maxCnt=0, maxRow, maxCol;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1 && visited[i][j]==false) {
                    int walls=0, cnt=0;
                    set<pair<int,int>> counted;
                    find(grid, visited, counted, i, j, m, n, cnt, walls);
                    if (cnt>maxCnt) {
                        maxCnt=cnt;
                        maxWalls=walls;
                        maxRow=i;
                        maxCol=j;
                    }
                }
            }
        }
        
        quarantine(grid, maxRow, maxCol, m, n);
        
        visited=vector<vector<bool>>(m, vector<bool>(n));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1 && visited[i][j]==false) {
                    spread(grid, visited, i, j, m, n);
                }
            }
        }
        
        return maxWalls;
    }
    
    void find(vector<vector<int>>& grid, vector<vector<bool>>& visited, set<pair<int,int>>& counted, int row, int col, int m, int n, int& cnt, int& walls)   {
        visited[row][col]=true;
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n) {
                if (grid[nr][nc]==0) {
                    if (counted.find({nr,nc})==counted.end()) {
                        cnt++;
                        counted.insert({nr,nc});
                    }
                    walls++;                    
                }  else if (grid[nr][nc]==1 && visited[nr][nc]==false) {
                    find(grid, visited, counted, nr, nc, m, n, cnt, walls);
                }
            }
        }
    }
    
    void quarantine(vector<vector<int>>& grid, int row, int col, int m, int n) {
        grid[row][col]=-1;
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) {
                quarantine(grid, nr, nc, m, n);
            }
        }        
    }
    
    void spread(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int m, int n) {
        visited[row][col]=true;
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==false) {
                if (grid[nr][nc]==0) {
                    grid[nr][nc]=1;
                    visited[nr][nc]=true;
                } else if (grid[nr][nc]==1) {
                    spread(grid, visited, nr, nc, m, n);
                }
            }
        }        
    }
    
    const int delta[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
};

