Objec­tive: Given a binary tree, Find whether if a Given Binary Tree is Balanced?

What is bal­anced Tree: A bal­anced tree is a tree in which dif­fer­ence between heights of sub-trees of any node in the tree is not greater than one.

Input: A Binary Tree

Out­put: True and false based on whether tree is bal­anced or not.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
	int isBalanced(TreeNode *root) {
		if (root==NULL) return 0;
		int l=isBalanced(root->left);
		int r=isBalanced(root->right);
		if (l==-1 || r==-1 || abs(l-r)>1) return -1;

		return 1+max(l, r);
	}
	bool isBalancedTree(TreeNode *root) {
		int res=isBalanced(root);
		return res>=0;
	}
};

