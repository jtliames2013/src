63. Unique Paths II  
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Hide Company Tags Bloomberg
Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Unique Paths

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

2.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if (m==0) return 0;
        int n=obstacleGrid[0].size();
        if (n==0) return 0;
    
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0&&j==0) dp[i][j]=obstacleGrid[i][j]==0?1:0;
                else {
                    if (obstacleGrid[i][j]==0) {
                        if (i>0) dp[i][j]+=dp[i-1][j];
                        if (j>0) dp[i][j]+=dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};

int main()
{
	return 0;
}


