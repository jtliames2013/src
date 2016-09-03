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
	int getLiveNeighbors(vector<vector<int> >& board, int i, int j) {
		int row=board.size();
		int col=board[0].size();

		int live=0;
		if (i>0) {
			live += board[i-1][j] & 1;
			if (j>0) {
				live += board[i-1][j-1] & 1;
			}
			if (j<col-1) {
				live += board[i-1][j+1] & 1;
			}
		}

		if (j>0) {
			live += board[i][j-1] & 1;
		}
		if (j<col-1) {
			live += board[i][j+1] & 1;
		}

		if (i<row-1) {
			live += board[i+1][j] & 1;
			if (j>0) {
				live += board[i+1][j-1] & 1;
			}
			if (j<col-1) {
				live += board[i+1][j+1] & 1;
			}
		}

		return live;
	}

    void gameOfLife(vector<vector<int>>& board) {
    	if (board.size()==0) return;
    	if (board[0].size()==0) return;

    	int row=board.size();
    	int col=board[0].size();
    	for (int i=0; i<row; i++) {
    		for (int j=0; j<col; j++) {
    			int live=getLiveNeighbors(board, i, j);
    			if ((board[i][j] & 1 )== 0) {
    				if (live==3) {
    					board[i][j] |= 2;
    				}
    			} else {
    				if (live<2 || live>3) {
    					board[i][j] &= 1;
    				} else {
    					board[i][j] |= 2;
    				}
    			}
    		}
    	}

    	for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				board[i][j] >>= 1;
			}
    	}
    }
};

int main()
{
	Solution s;
	vector<vector<int> > b(4, vector<int>(4, 0));
	b[0][0]=0; b[0][1]=0; b[0][2]=0; b[0][3]=0;
	b[1][0]=0; b[1][1]=1; b[1][2]=1; b[1][3]=0;
	b[2][0]=0; b[2][1]=1; b[2][2]=1; b[2][3]=0;
	b[3][0]=0; b[3][1]=0; b[3][2]=0; b[3][3]=0;
	s.gameOfLife(b);
	return 0;
}


