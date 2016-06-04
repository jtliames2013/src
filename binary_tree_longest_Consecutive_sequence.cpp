 Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,

   1
    \
     3
    / \
   2   4
        \
         5

Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1

Longest consecutive sequence path is 2-3,not3-2-1, so return 2. 

1. Use top-down.  

  class Solution {
  public:
	  int longest(TreeNode* curr, TreeNode* parent, int len) {
		  if (curr==NULL) return len;
		  len = (parent!=NULL && parent->val==curr->val-1) ? len+1 : 1;
		  return max(len, max(longest(curr->left, curr, len), longest(curr->right, curr, len)));
	  }

      int longestConsecutive(TreeNode* root) {
    	  return longest(root, NULL, 0);
      }
  };

2. Use bottome up. Need to return the global max and local max. Also need to run both left and right to update global max
no matter it is consecutive or not.

  class Solution {
  public:
	  int maxVal;

	  // return longest consecutive till curr
	  int longest(TreeNode* curr) {
		  if (curr==NULL) return 0;
		  int localmax=1;

		  int left=longest(curr->left);
		  int right=longest(curr->right);
		  if (curr->left!=NULL && curr->left->val==curr->val+1) {
			  localmax=max(left+1, localmax);
		  }

		  if (curr->right!=NULL && curr->right->val==curr->val+1) {
			  localmax=max(right+1, localmax);
		  }

		  maxVal=max(maxVal, localmax);

		  return localmax;
	  }

      int longestConsecutive(TreeNode* root) {
    	  maxVal=0;
    	  longest(root);
    	  return maxVal;
      }
  };

