419. Battleships in a Board Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 21070
Total Submissions: 34474
Difficulty: Medium
Contributors:
ben65
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.

Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?

Going over all cells, we can count only those that are the "first" cell of the battleship. First cell will be defined as the most top-left cell. We can check for first cells by only counting cells that do not have an 'X' to the left and do not have an 'X' above them.

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        if (m==0) return 0;
        int n=board[0].size();
        if (n==0) return 0;
        int res=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j]=='X') {
                    if ((i==0||board[i-1][j]!='X') && (j==0||board[i][j-1]!='X')) res++;
                }
            }
        }
        
        return res;
    }
};

