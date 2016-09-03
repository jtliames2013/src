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

2.
class Solution {

public:

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {

        int delta[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};    

        queue<pair<int,int>> q;

        q.push(make_pair(i, j));

        visited[i][j]=true;

        

        while (!q.empty()) {

            pair<int,int> f=q.front();

            q.pop();

            

            for (int k=0; k<4; k++) {

                int x=f.first+delta[k][0];

                int y=f.second+delta[k][1];

                

                if (x>=0 && x<m && y>=0 && y<n && visited[x][y]==false) {

                    if (grid[x][y]=='1') {

                        q.push(make_pair(x,y));

                        visited[x][y]=true;

                    }

                }

            }

        }

    }

    

    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size();

        if (m==0) return 0;

        int n=grid[0].size();

        if (n==0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int num=0;

        

        for (int i=0; i<m; i++) {

            for (int j=0; j<n; j++) {

                if (grid[i][j]=='1' && visited[i][j]==false) {

                    bfs(grid, visited, i, j, m, n);

                    num++;

                }

            }

        }

        

        return num;

    }

};


int main()
{
	return 0;
}


