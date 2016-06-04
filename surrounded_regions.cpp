#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

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

class Solution {
public:
    void solve(vector<vector<char>> &board) {
    	queue<pair<int, int> > keep;
    	int row = board.size();
    	if (row == 0) return;
    	int col = board[0].size();

    	for (int i=0; i<row; i++)
    	{
    		if (board[i][0] == 'O') keep.push(make_pair(i, 0));
    		if (board[i][col-1] == 'O') keep.push(make_pair(i, col-1));
    	}

    	for (int i=0; i<col; i++)
    	{
    		if (board[0][i] == 'O') keep.push(make_pair(0, i));
    		if (board[row-1][i] == 'O') keep.push(make_pair(row-1, i));
    	}

    	while (!keep.empty())
    	{
    		pair<int, int> p = keep.front();
    		keep.pop();
    		board[p.first][p.second] = 'Y';

    		if (p.first > 0 && board[p.first-1][p.second] == 'O') keep.push(make_pair(p.first-1, p.second));
    		if (p.second >0 && board[p.first][p.second-1] =='O') keep.push(make_pair(p.first, p.second-1));
    		if (p.first < row-1 && board[p.first+1][p.second] == 'O') keep.push(make_pair(p.first+1, p.second));
    		if (p.second < col-1 && board[p.first][p.second+1] == 'O') keep.push(make_pair(p.first, p.second+1));
    	}

    	for (int i=0; i<row; i++)
    	{
    		for (int j=0; j<col; j++)
    		{
    			if (board[i][j] == 'Y') board[i][j] = 'O';
    			else if (board[i][j] == 'O') board[i][j] = 'X';
    		}
    	}
    }
};

int main()
{
	return 0;
}

