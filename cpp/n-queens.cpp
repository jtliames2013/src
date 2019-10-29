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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos;
        dfs(res, pos, n, 0);

        return res;
    }
private:
    void dfs(vector<vector<string>>& res, vector<int>& pos, int n, int start) {
        if (start==n) {
            res.push_back(convert(pos, n));
            return;
        }
        
        for (int col=0; col<n; ++col) {
            if (isValid(pos, col)) {
                pos.push_back(col);
                dfs(res, pos, n, start+1);
                pos.pop_back();
            }
        }
    }

    bool isValid(vector<int>& pos, int col) {
        int row=pos.size();
        for (int i=0; i<pos.size(); ++i) {
            if (pos[i]==col || abs(pos[i]-col)==row-i) return false;
        }
        return true;
    }
    
    vector<string> convert(vector<int>& pos, int n) {
        vector<string> res;
        for (auto p:pos) {
            string line;
            for (int i=0; i<n; ++i) {
                if (i==p) line+='Q';
                else line+='.';
            }
            res.push_back(line);
        }
        return res;
    }
};
