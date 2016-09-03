270. Closest Binary Search Tree Value 
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

    Given target value is a floating point.
    You are guaranteed to have only one unique value in the BST that is closest to the target.

1. Use recursion and compare left and right.

  class Solution {
  public:
      int closestValue(TreeNode* root, double target) {
    	  if (root==NULL) return INT_MAX;
    	  if (root->left==NULL && root->right==NULL) return root->val;

    	  int closest=root->val;
    	  int closestChild;
    	  if (root->val > target && root->left!=NULL) {
    		  closestChild=closestValue(root->left, target);
    		  closest=abs(root->val-target)<abs(closestChild-target) ? root->val : closestChild;
    	  }
    	  if (root->val < target && root->right!=NULL) {
    		  closestChild=closestValue(root->right, target);
    		  closest=abs(closest-target)<abs(closestChild-target) ? closest : closestChild;
    	  }
    	  return closest;
      }
  };


2. Use iteratively search down BST, record left and right along the way.

  class Solution {
  public:
      int closestValue(TreeNode* root, double target) {
    	  if (root==NULL) return INT_MAX;

    	  long long left=LLONG_MAX, right=LLONG_MAX;
    	  TreeNode *node=root;
    	  while (node!=NULL) {
    		  if (node->val==target) return node->val;
    		  else if (node->val>target) {
    			  right=node->val;
    			  node=node->left;
    		  } else {
    			  left=node->val;
    			  node=node->right;
    		  }
    	  }

    	  return (abs(left-target)<abs(right-target) ? left : right);
      }
  };

