#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

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

int main()
{
	return 0;
}

