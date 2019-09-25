1020. Number of Enclaves
Medium

123

16

Favorite

Share
Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: 
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.
Example 2:

Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: 
All 1s are either on the boundary or can reach the boundary.
 

Note:

1 <= A.length <= 500
1 <= A[i].length <= 500
0 <= A[i][j] <= 1
All rows have the same size.

1. BFS
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m=A.size(), n=A[0].size(), res=0;
        queue<pair<int,int>> q;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; ++j) {
                res+=A[i][j];
                if ((i==0 || i==m-1 || j==0 || j==n-1) && A[i][j]==1){
                    q.push({i, j});
                    A[i][j]=2;
                }
            }
        }
        
        while (!q.empty()) {
            auto f=q.front();
            q.pop();
            res--;
            
            for (int k=0; k<4; ++k) {
                int nr=f.first+delta[k][0];
                int nc=f.second+delta[k][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n && A[nr][nc]==1) {
                    A[nr][nc]=2;
                    q.push({nr, nc});
                }
            }
        }
        
        return res;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

2. DFS
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m=A.size(), n=A[0].size(), res=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; ++j) {
                if ((i==0 || i==m-1 || j==0 || j==n-1) && A[i][j]==1){                    
                    dfs(A, m, n, i, j);
                }
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; ++j) {
                if (A[i][j]==1) res++;
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& A, int m, int n, int row, int col) {
        A[row][col]=2;
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && A[nr][nc]==1) {
                dfs(A, m, n, nr, nc);
            }
        }
    }
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
