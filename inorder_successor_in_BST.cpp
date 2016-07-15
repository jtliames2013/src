285. Inorder Successor in BST 
 Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null. 

NOTE: when curr node value is greater than p's value, mark curr node as potential successor and go left. Otherwise go right.
1. The leftmost child of the right child, if your current node has a right child. If the right child has no left child, the right child is your inorder successor.

2. Navigate up the parent ancestor nodes, and when you find a parent whose left child is the node you're currently at, the parent is the inorder successor of your original node.


  class Solution {
  public:
      TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	  TreeNode* succ=NULL;
    	  while (root!=NULL) {
    		  if (root->val>p->val) {
    			  succ=root;
    			  root=root->left;
    		  } else {
    			  root=root->right;
    		  }
    	  }
    	  return succ;
      }
  };

