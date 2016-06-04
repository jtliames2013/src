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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int row=obstacleGrid.size();
    	if (row==0) return 0;
    	int col=obstacleGrid[0].size();
    	if (col==0) return 0;

    	int res[row][col];
    	for (int i=0; i<row; i++) {
    		for (int j=0; j<col; j++) {
    			if (obstacleGrid[i][j]==1) {
    				res[i][j]=0;
    			}
    			else
    			{
					if (i==0 && j==0) {
						res[i][j]=1;
					} else if (i==0) {
						res[i][j]=res[i][j-1];
					} else if (j==0) {
						res[i][j]=res[i-1][j];
					} else {
						res[i][j]=res[i-1][j]+res[i][j-1];
					}
    			}
    		}
    	}

    	return res[row-1][col-1];
    }
};

int main()
{
	return 0;
}


