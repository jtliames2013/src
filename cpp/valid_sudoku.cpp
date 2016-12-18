36. Valid Sudoku  
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Hide Company Tags Snapchat Uber Apple
Hide Tags Hash Table
Hide Similar Problems (H) Sudoku Solver

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
	void initFlag(vector<bool> &f)
	{
		for (int i = 0; i < 9; i++) f.push_back(false);
	}

    bool isValidSudoku(vector<vector<char> > &board) {
    	vector<bool> flag;

    	for (int row = 0; row < 9; row++)
    	{
    		flag.clear();
    		initFlag(flag);

    		for (int i = 0; i < 9; i++)
    		{
    			if (board[row][i] != '.')
    			{
    				if (flag[board[row][i] - '1'] == true)
    				{
    					return false;
    				}
    				else
    				{
    					flag[board[row][i] - '1'] = true;
    				}
    			}
    		}
    	}

		for (int col = 0; col < 9; col++)
		{
			flag.clear();
			initFlag(flag);

			for (int i = 0; i < 9; i++)
			{
				if (board[i][col] != '.')
				{
					if (flag[board[i][col] - '1'] == true)
					{
						return false;
					}
					else
					{
						flag[board[i][col] - '1'] = true;
					}
				}
			}
		}

		for (int row = 0; row < 3; row++)
		{
			for (int col= 0; col < 3; col++)
			{
				flag.clear();
				initFlag(flag);
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (board[row * 3 + i][col * 3 + j] != '.')
						{
							if (flag[board[row * 3 + i][col * 3 + j] - '1'] == true)
							{
								return false;
							}
							else
							{
								flag[board[row * 3 + i][col * 3 + j] - '1'] = true;
							}
						}
					}
				}
			}
		}

    	return true;
    }
};

2. Use bit vector
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row=0; row<9; row++) {
            bitset<9> flag;
            for (int i=0; i<9; i++) {
                if (board[row][i]!='.') {
                    if (flag.test(board[row][i]-'1')) return false;
                    else flag.set(board[row][i]-'1');
                }
            }
        }
        
        for (int col=0; col<9; col++) {
            bitset<9> flag;
            for (int i=0; i<9; i++) {
                if (board[i][col]!='.'){
                    if (flag.test(board[i][col]-'1')) return false;
                    else flag.set(board[i][col]-'1');
                }
            }
        }
        
        for (int blockRow=0; blockRow<3; blockRow++) {
            for (int blockCol=0; blockCol<3; blockCol++) {
                bitset<9> flag;
                for (int i=0; i<3; i++) {
                    for (int j=0; j<3; j++) {
                        if (board[blockRow*3+i][blockCol*3+j]!='.') {
                            if (flag.test(board[blockRow*3+i][blockCol*3+j]-'1')) return false;
                            else flag.set(board[blockRow*3+i][blockCol*3+j]-'1');
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

int main()
{
	return 0;
}

