417. Pacific Atlantic Water Flow  QuestionEditorial Solution  My Submissions
Total Accepted: 1095 Total Submissions: 3703 Difficulty: Medium
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
Subscribe to see which companies asked this question

Hide Tags Depth-first Search Breadth-first Search

class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int row, int col, int m, int n) {
        visited[row][col]=true;
        
        int delta[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==false && matrix[nr][nc]>=matrix[row][col]) {
                dfs(matrix, visited, nr, nc, m, n);
            }
        }
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> res;
        int m=matrix.size();
        if (m==0) return res;
        int n=matrix[0].size();
        if (n==0) return res;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int i=0; i<m; i++) {
            dfs(matrix, pacific, i, 0, m, n);
            dfs(matrix, atlantic, i, n-1, m, n);
        }
        
        for (int j=0; j<n; j++) {
            dfs(matrix, pacific, 0, j, m, n);
            dfs(matrix, atlantic, m-1, j, m, n);
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
        
        return res;
    }
};

