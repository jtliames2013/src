51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Hide Tags Backtracking
Hide Similar Problems (H) N-Queens II

class Solution {
public:
    vector<string> getConfig(int n, vector<int>& pos) {
        vector<string> res;
        for (int i=0; i<n; i++) {
            string line;
            for (int j=0; j<n; j++) {
                if (j==pos[i]) line+="Q";
                else line+=".";
            }
            res.push_back(line);
        }
        return res;
    }
    
    bool isValid(int row, int col, vector<int>& pos) {
        for (int i=0; i<pos.size(); i++) {
            if (pos[i]==col || abs(pos[i]-col)==row-i) return false;
        }   
        return true;
    }
    
    void solve(vector<vector<string>>& res, int n, vector<int>& pos, int row) {
        if (row==n) {
            vector<string> config=getConfig(n, pos);
            res.push_back(config);
            return;
        }    
        
        for (int col=0; col<n; col++) {
            if (isValid(row, col, pos)) {
                pos.push_back(col);
                solve(res, n, pos, row+1);
                pos.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos;
        solve(res, n, pos, 0);
        
        return res;
    }
};

