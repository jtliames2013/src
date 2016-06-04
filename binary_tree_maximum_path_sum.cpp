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
	 int findMaxPathSum(TreeNode* root, int& maxSum) {
		 if (root==NULL) return 0;
		 int leftStraight=0, rightStraight=0;
		 int straight, angle;

		 if (root->left!=NULL) {
			 leftStraight = max(findMaxPathSum(root->left, maxSum), 0);
		 }

		 if (root->right!=NULL) {
			 rightStraight = max(findMaxPathSum(root->right, maxSum), 0);
		 }

		 straight=max(leftStraight, rightStraight)+root->val;
		 angle=leftStraight+rightStraight+root->val;
		 maxSum = max(maxSum, angle);

		 return straight;
	 }

     int maxPathSum(TreeNode* root) {
    	 int maxSum=INT_MIN;
    	 if (root==NULL) return 0;
    	 findMaxPathSum(root, maxSum);
    	 return maxSum;
     }
 };

int main()
{
	return 0;
}

