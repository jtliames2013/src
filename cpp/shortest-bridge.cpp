934. Shortest Bridge
Medium

376

29

Favorite

Share
In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

Example 1:

Input: [[0,1],[1,0]]
Output: 1
Example 2:

Input: [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Note:

1 <= A.length = A[0].length <= 100
A[i][j] == 0 or A[i][j] == 1

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m=A.size(), n=A[0].size(), res=0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int,int>> q;
        bool done=false;
        for (int i=0; i<m; ++i) {
            if (done) break;
            for (int j=0; j<n; ++j) {
                if (A[i][j]==1) {
                    dfs(A, visited, q, m, n, i, j);
                    done=true;
                    break;
                }
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
                    if (nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==false) {
                        visited[nr][nc]=true;
                        if (A[nr][nc]==1) return res;
                        else q.push({nr, nc});
                    } 
                }
            }
            res++;
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& A, vector<vector<bool>>& visited, queue<pair<int,int>>& q, int m, int n, int row, int col) {
        visited[row][col]=true;
        q.push({row, col});
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && A[nr][nc]==1 && visited[nr][nc]==false) {
                dfs(A, visited, q, m, n, nr, nc);
            }
        }
    }

    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
