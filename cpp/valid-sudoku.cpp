36. Valid Sudoku  
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Hide Company Tags Snapchat Uber Apple
Hide Tags Hash Table
Hide Similar Problems (H) Sudoku Solver

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int size=9;
        for (int row=0; row<size; row++) {
            bitset<size> b;
            for (int col=0; col<size; col++) {
                if (board[row][col]!='.') {
                    if (b.test(board[row][col]-'1')) return false;
                    b.set(board[row][col]-'1');
                }
            }
        }
        
        for (int col=0; col<size; col++) {
            bitset<size> b;
            for (int row=0; row<size; row++) {
                if (board[row][col]!='.') {
                    if (b.test(board[row][col]-'1')) return false;
                    b.set(board[row][col]-'1');
                }
            }
        }
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                bitset<size> b;
                for (int r=0; r<3; r++) {
                    for (int c=0; c<3; c++) {
                        int row=i*3+r;
                        int col=j*3+c;
                        if (board[row][col]!='.') {
                            if (b.test(board[row][col]-'1')) return false;    
                            b.set(board[row][col]-'1');
                        }
                    }
                }
            }
        }
        return true;
    }
};

