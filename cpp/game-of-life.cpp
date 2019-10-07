289. Game of Life  QuestionEditorial Solution  My Submissions
Total Accepted: 22348 Total Submissions: 63629 Difficulty: Medium
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Company Tags Dropbox Google Snapchat
Hide Tags Array
Hide Similar Problems (M) Set Matrix Zeroes

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        if (m==0) return;
        int n=board[0].size();
        if (n==0) return;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int count=0;
                for (int k=0; k<8; k++) {
                    int nr=i+delta[k][0];
                    int nc=j+delta[k][1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n) {
                        if (board[nr][nc] & 0x1 == 1) count++;
                        if (count>3) break;
                    }
                }
                if (board[i][j] & 0x1 == 1) {
                    if (count==2||count==3) board[i][j] |= 0x2;
                } else {
                    if (count==3) board[i][j] |= 0x2;
                }
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
private:
      const int delta[8][2]={{-1,-1},{-1,0}, {-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
};

