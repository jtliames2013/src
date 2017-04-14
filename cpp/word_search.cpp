79. Word Search 
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
Hide Company Tags Microsoft Bloomberg Facebook
Hide Tags Array Backtracking
Hide Similar Problems (H) Word Search II

class Solution {
public:
    bool exist(vector<vector<char>>& board, int row, int col, int m, int n, string& word, int start, vector<vector<bool>>& visited) {
		// Need to compare first. A board with only one character ['a'] has no neighbor   
        if (board[row][col]!=word[start]) return false;
        start++;
        if (start==word.size()) return true;
        visited[row][col]=true;
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==false) {
                if (exist(board, nr, nc, m, n, word, start, visited)) return true;
            }
        }
        visited[row][col]=false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if (m==0) return false;
        int n=board[0].size();
        if (n==0) return false;
        if (word.empty()) return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (exist(board, i, j, m, n, word, 0, visited)) return true;
            }
        }
        return false;
    }
private:
    int delta[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
};

