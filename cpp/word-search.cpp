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
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if (m==0) return false;
        int n=board[0].size();
        if (n==0) return false;
        if (word.empty()) return false;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (dfs(board, i, j, m, n, word, 0)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, int row, int col, int m, int n, string& word, int start) {
        if (start==word.size()) return true;
        if (row<0 || row>=m || col<0 || col>=n) return false;
        if (board[row][col]!=word[start]) return false;
        char c=board[row][col];
        board[row][col]='#';
        if (dfs(board, row+1, col, m, n, word, start+1) ||
            dfs(board, row-1, col, m, n, word, start+1) ||
            dfs(board, row, col+1, m, n, word, start+1) ||
            dfs(board, row, col-1, m, n, word, start+1)) return true;
        board[row][col]=c;
        return false;
    }
};

