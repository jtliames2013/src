250. Count Univalue Subtrees
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,

              5
             / \
            1   5
           / \   \
          5   5   5

return 4. 

NOTE: at each node, return if curr subtree is unival. And increment count if so.

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
#include <unordered_map>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

  class Solution {
  public:
	  int count;
	  bool isUnivalSubtrees(TreeNode* root) {
		  if (root==NULL) return true;

		  bool left = (root->left==NULL || (isUnivalSubtrees(root->left) && root->left->val==root->val));
		  bool right = (root->right==NULL || (isUnivalSubtrees(root->right) && root->right->val==root->val));

		  if (left && right) {
			  count++;
			  return true;
		  } else {
			  return false;
		  }
	  }

      int countUnivalSubtrees(TreeNode* root) {
    	  count=0;
    	  isUnivalSubtrees(root);

    	  return count;
      }
  };

int main()
{
	return 0;
}

