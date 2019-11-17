37. Sudoku Solver
DescriptionHintsSubmissionsSolutions
Total Accepted: 72977
Total Submissions: 247660
Difficulty: Hard
Contributor: LeetCode
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.

Subscribe to see which companies asked this question.

Hide Tags Backtracking Hash Table
Hide Similar Problems (M) Valid Sudoku

class Solution {
public:
	bool isValid(vector<vector<char> >& board, int row, int col) {
		for (int c=0; c<9; c++) {
			if (c!=col && board[row][c] == board[row][col]) return false;
		}

		for (int r=0; r<9; r++) {
			if (r!=row && board[r][col] == board[row][col]) return false;
		}

		int br=row/3;
		int bc=col/3;

		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				if ((i+br*3 != row || j+bc*3 != col) && board[i+br*3][j+bc*3]==board[row][col]) return false;
			}
		}

		return true;
	}

	bool solveSudoku(vector<vector<char> >& board, int row, int col) {
		if (row==9) return true;

		int nextrow, nextcol;
		if (col==8) {
			nextrow=row+1;
			nextcol=0;
		} else {
			nextrow=row;
			nextcol=col+1;
		}

		if (board[row][col]=='.') {
			for (int i=1; i<=9; i++) {
				board[row][col]='0'+i;
				if (isValid(board, row, col)) {
					if (solveSudoku(board, nextrow, nextcol)) {
						return true;
					}
				}
			}

			board[row][col]='.';
			return false;
		} else {
			return solveSudoku(board, nextrow, nextcol);
		}
	}

    void solveSudoku(vector<vector<char>>& board) {
    	if (board.size()!=9) return;
    	if (board[0].size()!=9) return;

    	solveSudoku(board, 0, 0);
    }
};

2.
class Solution {
public:
	bool solveSudoku(vector<vector<char> >& board, int row, int col) {
	    if (row>=9) return true;
	    int nextRow, nextCol;
	    if (col<8) {
	        nextRow=row;
	        nextCol=col+1;
	    } else {
	        nextRow=row+1;
	        nextCol=0;
	    }
	    
	    if (board[row][col]=='.') {
	        for (int i=0; i<9; i++) {
	            int idx=(row/3)*3+col/3;
	            if (rows[row].test(i)==false && 
	                cols[col].test(i)==false && 
	                blocks[idx].test(i)==false) {
	                    board[row][col]='1'+i;
	                    rows[row].set(i);
	                    cols[col].set(i);
	                    blocks[idx].set(i);
	                    if (solveSudoku(board, nextRow, nextCol)) return true;
	                    rows[row].reset(i);
	                    cols[col].reset(i);
	                    blocks[idx].reset(i);
	                }
	        }
	        
	        board[row][col]='.';
	        return false;
	    } else {
	        return solveSudoku(board, nextRow, nextCol);
	    }
	}

    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(9);
        cols.resize(9);
        blocks.resize(9);
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j]!='.') {
                    rows[i].set(board[i][j]-'1');
                    cols[j].set(board[i][j]-'1');
                    int idx=(i/3)*3+j/3;
                    blocks[idx].set(board[i][j]-'1');
                }
            }
        }
    	solveSudoku(board, 0, 0);
    }
private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<bitset<9>> blocks;
};

