329. Longest Increasing Path in a Matrix
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4

The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Depth-first Search Topological Sort Memoization

记忆化搜索。

设dis[i][j]为当前点出发最大上升路径的值。初始设置为0，表示该点未知，需要更新。

再次碰到的时候只需要返回该值即可。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>

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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

  // Definition for a point.
  struct Point {
       int x;
       int y;
       Point() : x(0), y(0) {}
       Point(int a, int b) : x(a), y(b) {}
  };

  class Solution {
  public:
	  int findPath(vector<vector<int> >& matrix, vector<vector<int> >& dp, int rIdx, int cIdx) {
		  if (dp[rIdx][cIdx]) return dp[rIdx][cIdx];

		  int row=matrix.size();
		  int col=matrix[0].size();

		  if (rIdx>0 && matrix[rIdx-1][cIdx]>matrix[rIdx][cIdx]) {
			  dp[rIdx][cIdx]=max(dp[rIdx][cIdx], findPath(matrix, dp, rIdx-1, cIdx));
		  }

		  if (cIdx>0 && matrix[rIdx][cIdx-1]>matrix[rIdx][cIdx]) {
			  dp[rIdx][cIdx]=max(dp[rIdx][cIdx], findPath(matrix, dp, rIdx, cIdx-1));
		  }

		  if (rIdx<row-1 && matrix[rIdx+1][cIdx]>matrix[rIdx][cIdx]) {
			  dp[rIdx][cIdx]=max(dp[rIdx][cIdx], findPath(matrix, dp, rIdx+1, cIdx));
		  }

		  if (cIdx<col-1 && matrix[rIdx][cIdx+1]>matrix[rIdx][cIdx]) {
			  dp[rIdx][cIdx]=max(dp[rIdx][cIdx], findPath(matrix, dp, rIdx, cIdx+1));
		  }

		  return ++dp[rIdx][cIdx];
	  }

      int longestIncreasingPath(vector<vector<int>>& matrix) {
    	  int maxPath=0;
    	  int row=matrix.size();
    	  if (row==0) return 0;
    	  int col=matrix[0].size();
    	  if (col==0) return 0;
		  vector<vector<int> > dp(row, vector<int>(col, 0));

    	  for (int i=0; i<row; i++) {
    		  for (int j=0; j<col; j++) {
    			  int localmax=findPath(matrix, dp, i, j);
    			  maxPath=max(localmax, maxPath);
    		  }
    	  }

    	  return maxPath;
      }
  };

2.
class Solution {
public:
    int findPath(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int m, int n) {
        if (dp[i][j]!=0) return dp[i][j];
        
        int neighbor[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for (int k=0; k<4; k++) {
            int x=i+neighbor[k][0];
            int y=j+neighbor[k][1];
            
            if (x>=0 && x<m && y>=0 && y<n) {
                if (matrix[x][y]>matrix[i][j]) {
                    dp[i][j]=max(dp[i][j], findPath(matrix, dp, x, y, m, n));
                }
            }
        }
        return ++dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxpath=0;
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int localmax=findPath(matrix, dp, i, j, m, n);
                maxpath=max(maxpath, localmax);
            }
        }
        
        return maxpath;
    }
};

int main()
{
	return 0;
}

