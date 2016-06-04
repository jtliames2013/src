#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

 class Solution {
 public:
     int minDistance(string word1, string word2) {
    	 int m=word1.size();
    	 int n=word2.size();
    	 vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    	 for (int i=0; i<=m; i++) {
    		 dp[i][0]=i;
    	 }
    	 for (int j=0; j<=n; j++) {
    		 dp[0][j]=j;
    	 }

    	 for (int i=1; i<=m; i++) {
    		 for (int j=1; j<=n; j++) {
    			 dp[i][j]=dp[i-1][j-1];
    			 if (word1[i-1]!=word2[j-1]) dp[i][j]++;
    			 dp[i][j]=min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i][j]);
    		 }
    	 }

    	 return dp[m][n];
     }
 };

int main()
{
	return 0;
}

