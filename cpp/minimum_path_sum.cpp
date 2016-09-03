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

1. use 2d array

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if (grid.size()==0 || grid[0].size()==0) return 0;

    	int row=grid.size();
    	int col=grid[0].size();
    	vector<vector<int> > res(row, vector<int>(col));

    	for (int i=0; i<row; i++)
    	{
    		for (int j=0; j<col; j++)
    		{
    			if (i==0 && j==0) {
    				res[i][j] = grid[i][j];
    			} else if (i==0) {
    				res[i][j] = res[i][j-1] + grid[i][j];
    			} else if (j==0) {
    				res[i][j] = res[i-1][j] + grid[i][j];
    			} else {
    				res[i][j] = (res[i-1][j] > res[i][j-1] ? res[i][j-1] : res[i-1][j]) + grid[i][j];
    			}
    		}
    	}

    	return res[row-1][col-1];
    }
};

2. use 1d array

class Solution {

public:

    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();

        if (m==0) return 0;

        int n=grid[0].size();

        if (n==0) return 0;

        

        vector<int> dp(n, 0);

        int num=0;

        for (int j=0; j<n; j++) {

            num+=grid[0][j];

            dp[j]=num;

        }

        

        num=grid[0][0];

        for (int i=1; i<m; i++) {

            num+=grid[i][0];

            dp[0]=num;

            for (int j=1; j<n; j++) {

                dp[j]=min(dp[j-1], dp[j])+grid[i][j];

            }

        }

        

        return dp[n-1];

    }

};

int main()
{
	return 0;
}

