62. Unique Paths  
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Hide Company Tags Bloomberg
Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Unique Paths II (M) Minimum Path Sum (H) Dungeon Game

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
    int uniquePaths(int m, int n) {
    	if (m==0 || n==0) return 0;

    	int res[m][n];

    	for (int i=0; i<m; i++)
    	{
    		for (int j=0; j<n; j++)
    		{
    			if (i==0 && j==0) res[i][j]=1;
    			else if (i==0) res[i][j]=res[i][j-1];
    			else if (j==0) res[i][j]=res[i-1][j];
    			else res[i][j]=res[i-1][j]+res[i][j-1];
    		}
    	}

    	return res[m-1][n-1];
    }
};

2.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0&&j==0) dp[i][j]=1;
                else {
                    if (i>0) dp[i][j]+=dp[i-1][j];
                    if (j>0) dp[i][j]+=dp[i][j-1];
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

