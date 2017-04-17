130. Surrounded Regions  QuestionEditorial Solution  My Submissions
Total Accepted: 57838 Total Submissions: 349839 Difficulty: Medium
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Hide Tags Breadth-first Search Union Find
Hide Similar Problems (M) Number of Islands (M) Walls and Gates

1. BFS
class Solution {
public:
    void bfs(vector<vector<char>>& board, int row, int col, int m, int n) {
        queue<pair<int,int>> q;
        q.push({row,col});
        board[row][col]='Y';
        
        while (!q.empty()) {
            pair<int,int> f=q.front();
            q.pop();
            
            for (int k=0; k<4; k++) {
                int nr=f.first+delta[k][0];
                int nc=f.second+delta[k][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O') {
                    q.push({nr,nc});
                    board[nr][nc]='Y';
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if (m==0) return;
        int n=board[0].size();
        if (n==0) return;
        
        for (int j=0; j<n; j++) {
            if (board[0][j]=='O') bfs(board, 0, j, m, n);
            if (board[m-1][j]=='O') bfs(board, m-1, j, m, n);
        }
        
        for (int i=1; i<m-1; i++) {
            if (board[i][0]=='O') bfs(board, i, 0, m, n);
            if (board[i][n-1]=='O') bfs(board, i, n-1, m, n);
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

2. DFS
class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n) {
        board[row][col]='Y';
        
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O') {
                dfs(board, nr, nc, m, n);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if (m==0) return;
        int n=board[0].size();
        if (n==0) return;
        
        for (int j=0; j<n; j++) {
            if (board[0][j]=='O') dfs(board, 0, j, m, n);
            if (board[m-1][j]=='O') dfs(board, m-1, j, m, n);
        }
        
        for (int i=1; i<m-1; i++) {
            if (board[i][0]=='O') dfs(board, i, 0, m, n);
            if (board[i][n-1]=='O') dfs(board, i, n-1, m, n);
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

