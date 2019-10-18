542. 01 Matrix Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 4980
Total Submissions: 15329
Difficulty: Medium
Contributors:
Stomach_ache
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
Subscribe to see which companies asked this question.

Hide Tags Depth-first Search Breadth-first Search

1. BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0)  return matrix;
        int n=matrix[0].size();
        if (n==0) return matrix;

        queue<pair<int,int>> q;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j]==0) {
                    q.push({i,j});
                } else {
                    matrix[i][j]=INT_MAX;
                }
            }
        }
        
        while (!q.empty()) {
            pair<int,int> f=q.front();
            q.pop();
            for (int k=0; k<4; k++) {
                int nr=f.first+delta[k][0];
                int nc=f.second+delta[k][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[f.first][f.second]+1) {
                    q.push({nr,nc});
                    matrix[nr][nc]=matrix[f.first][f.second]+1;
                }
            }
        }

        return matrix;
    }
    
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};    
};


2. optimized DFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0) return matrix;
        int n=matrix[0].size();
        if (n==0) return matrix;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==1 && !hasZeroNeighbor(matrix, i, j, m, n)) matrix[i][j]=INT_MAX;
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==1) dfs(matrix, i, j, m, n);
            }
        }

        return matrix;
    }
private:
    bool hasZeroNeighbor(vector<vector<int>>& matrix, int row, int col, int m, int n) {
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]==0) return true;
        }
        return false;
    }

    void dfs(vector<vector<int>>& matrix, int row, int col, int m, int n) {
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[row][col]+1) {
                matrix[nr][nc]=matrix[row][col]+1;
                dfs(matrix, nr, nc, m, n);
            }
        }
    }

    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
