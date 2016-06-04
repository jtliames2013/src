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
	void bfs(vector<vector<char >>& grid, vector<vector<bool> >& visited, int m, int n) {
		int row=grid.size();
		int col=grid[0].size();
		queue<pair<int, int>> q;

		q.push(make_pair(m, n));
		visited[m][n]=true;

		while (!q.empty()) {
			pair<int, int> p=q.front();
			q.pop();

			if (p.first>0 && grid[p.first-1][p.second]=='1' && visited[p.first-1][p.second]==false) {
				q.push(make_pair(p.first-1, p.second));
				visited[p.first-1][p.second]=true;
			}
			if (p.second>0 && grid[p.first][p.second-1]=='1' && visited[p.first][p.second-1]==false) {
				q.push(make_pair(p.first, p.second-1));
				visited[p.first][p.second-1]=true;
			}
			if (p.first<row-1 && grid[p.first+1][p.second]=='1' && visited[p.first+1][p.second]==false) {
				q.push(make_pair(p.first+1, p.second));
				visited[p.first+1][p.second]=true;
			}
			if (p.second<col-1 && grid[p.first][p.second+1]=='1' && visited[p.first][p.second+1]==false) {
				q.push(make_pair(p.first, p.second+1));
				visited[p.first][p.second+1]=true;
			}
		}
	}

    int numIslands(vector<vector<char>>& grid) {
    	int row=grid.size();
    	if (row==0) return 0;
    	int col=grid[0].size();
    	if (col==0) return 0;
    	int count=0;

    	vector<vector<bool> > visited(row, vector<bool>(col));
    	for (int i=0; i<row; i++) {
    	    for (int j=0; j<col; j++) {
    	    	visited[i][j]=false;
    	    }
    	}

    	for (int i=0; i<row; i++) {
    		for (int j=0; j<col; j++) {
    			if (grid[i][j]=='1' && visited[i][j]==false) {
    				count++;
    				bfs(grid, visited, i, j);
    			}
    		}
    	}

    	return count;
    }
};

int main()
{
	return 0;
}


