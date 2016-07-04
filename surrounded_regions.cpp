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

Note: start from and mark the regions that is not surrounded first. Then rest of surrounded region is flipped.

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

2.

class Solution {

public:

    void solve(vector<vector<char>>& board) {

        int m=board.size();

        if (m==0) return;

        int n=board[0].size();

        if (n==0) return;

        

        queue<pair<int,int>> notSurrounded;

        for (int i=0; i<m; i++) {

            if (board[i][0]=='O') { notSurrounded.push(make_pair(i,0)); board[i][0]='Y'; }

            if (board[i][n-1]=='O') { notSurrounded.push(make_pair(i,n-1)); board[i][n-1]='Y'; }

        }

        for (int i=1; i<n-1; i++) {

            if (board[0][i]=='O') { notSurrounded.push(make_pair(0,i)); board[0][i]='Y'; }

            if (board[m-1][i]=='O') { notSurrounded.push(make_pair(m-1,i)); board[m-1][i]='Y'; }

        }

        

        int neighbor[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        while (!notSurrounded.empty()) {

            pair<int,int> f=notSurrounded.front();

            notSurrounded.pop();

            for (int k=0; k<4; k++) {

                int x=f.first+neighbor[k][0];

                int y=f.second+neighbor[k][1];

                if (x>=0 && x<m && y>=0 && y<n && board[x][y]=='O') {

                    notSurrounded.push(make_pair(x,y));

                    board[x][y]='Y';

                }

            }

        }

        

        for (int i=0; i<m; i++) {

            for (int j=0; j<n; j++) {

                if (board[i][j]=='Y') board[i][j]='O';

                else if (board[i][j]=='O') board[i][j]='X';

            }

        }

    }

};

int main()
{
	return 0;
}

