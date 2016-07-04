1D DP. DP size n+1. allocate matrix to cache isPalindrome result. 

整体的思路是一维DP。DP[i]表示长度为i的prefix：s[0: i-1]的min cut数量。
DP[i] = min (DP[j] + 1) ，对所有 0<=j<i，且s[j: i-1]为palindrome。
和I同样的技巧，用DP先计算存储一个palindrome判断矩阵isPal[i][j]，便于后面一维DP计算中能迅速判断s[j: i-1]是否为palindrome。


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
     int minCut(string s) {
    	 int size=s.size();
    	 if (size==0) return 0;
    	 vector<int> res(size+1, INT_MAX);
    	 vector<vector<bool> > isPal(size, vector<bool>(size, false));
    	 for (int i=0; i<size; i++) {
    		 for (int j=0; j<=i; j++) {
    			 if (j>=i-1 || (isPal[j+1][i-1]))
				 {
    				 if (s[i]==s[j]) isPal[j][i]=true;
				 }
    		 }
    	 }

    	 // if it is palindrome from begining, cut is 0
    	 res[0]=-1;
    	 for (int i=1; i<=size; i++) {
    		 for (int j=0; j<i; j++) {
    			 if (isPal[j][i-1]==true) {
    				 res[i]=min(res[i], res[j]+1);
    			 }
    		 }
    	 }

    	 return res[size];
     }
 };

int main()
{
	return 0;
}

