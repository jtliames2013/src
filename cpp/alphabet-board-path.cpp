1138. Alphabet Board Path
Medium

68

44

Favorite

Share
On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.



We may make the following moves:

'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

 

Example 1:

Input: target = "leet"
Output: "DDR!UURRR!!DDD!"
Example 2:

Input: target = "code"
Output: "RR!DDRR!UUL!R!"
 

Constraints:

1 <= target.length <= 100
target consists only of English lowercase letters.

class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int x=0, y=0;
        for (auto& c:target) {
            int nx=(c-'a')%5, ny=(c-'a')/5;
            // the order matters due to 'z'
            // U should be before L and R should be before D
            if (y>ny) res+=string(y-ny, 'U');            
            if (x>nx) res+=string(x-nx, 'L');
            if (x<nx) res+=string(nx-x, 'R');
            if (y<ny) res+=string(ny-y, 'D');            
            res+='!';            
            x=nx;
            y=ny;
        }
        return res;
    }
};
