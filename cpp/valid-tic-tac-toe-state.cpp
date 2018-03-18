794. Valid Tic-Tac-Toe State
DescriptionHintsSubmissionsDiscussSolution
A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
Note:

board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xcount=0, ocount=0, diag=0, antidiag=0;
        bool xwin, owin;
        vector<int> row(3), col(3);
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j]=='X') {
                    xcount++;
                    row[i]++;
                    col[j]++;
                    if (i==j) diag++;
                    if (i+j==2) antidiag++;
                } else if (board[i][j]=='O') {
                    ocount++;
                    row[i]--;
                    col[j]--;
                    if (i==j) diag--;
                    if (i+j==2) antidiag--; 
                }
            }
        }
        
        xwin = row[0]==3 || row[1]==3 || row[2]==3 ||
               col[0]==3 || col[1]==3 || col[2]==3 ||
               diag==3 || antidiag==3;
        owin = row[0]==-3 || row[1]==-3 || row[2]==-3 ||
               col[0]==-3 || col[1]==-3 || col[2]==-3 ||
               diag==-3 || antidiag==-3;
        
        if (xcount<ocount || xcount>ocount+1) return false;
        if (xwin && owin) return false;
        if ((xwin && xcount==ocount) || (owin && xcount>ocount)) return false;
        return true;
     }
};
