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
	bool existInBoard(vector<vector<char> >& board, vector<vector<bool> >& visited, string& word, int index, int i, int j) {
		if (index>=word.size()) {
			return false;
		} else if (index==word.size()-1) {
			if (board[i][j]==word[index]) {
				return true;
			} else {
				return false;
			}
		} else {
			if (board[i][j]!=word[index]) return false;
		}

		visited[i][j]=true;

		if (i>0) {
			if (visited[i-1][j]==false) {
				if (existInBoard(board, visited, word, index+1, i-1, j)) {
					return true;
				}
			}
		}

		if (j>0) {
			if (visited[i][j-1]==false) {
				if (existInBoard(board, visited, word, index+1, i, j-1)) {
					return true;
				}
			}
		}

		if (i<board.size()-1) {
			if (visited[i+1][j]==false) {
				if (existInBoard(board, visited, word, index+1, i+1, j)) {
					return true;
				}
			}
		}

		if (j<board[0].size()-1) {
			if (visited[i][j+1]==false) {
				if (existInBoard(board, visited, word, index+1, i, j+1)) {
					return true;
				}
			}
		}

		visited[i][j]=false;
		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
    	int row=board.size();
    	if (row==0) return false;
    	int col=board[0].size();
    	if (col==0) return false;
    	if (word.size()==0) return false;

    	vector<vector<bool> > visited(row, vector<bool>(col, false));

    	for (int i=0; i<row; i++) {
    		for (int j=0; j<col; j++) {
    			if (existInBoard(board, visited, word, 0, i, j)) {
    				return true;
    			}
    		}
    	}

    	return false;
    }
};

int main()
{
	return 0;
}


