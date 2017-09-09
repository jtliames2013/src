Binary Tree求and操作。(BST and)例如：
        *                  *                    *
      /   \              /   \                /    \
     1    *   and    *     0  =              *      0
         /  \          / \                 /  \.
        0   1        1   0              1   0
     Follow up: deepCopy(tree)
     Follow up2: 如何合并结果中出现的情况？. 
          * 
        /   \    =>      0
       0    0

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0), left(NULL), right(NULL) {}
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* treeAnd(TreeNode* t1, TreeNode* t2) {
		if (t1==NULL || t2==NULL) return NULL;
		if (isLeaf(t1) && isLeaf(t2)) {
			TreeNode *n=new TreeNode();
			if (t1->val==1 && t2->val==1) n->val=1;
			return n;
		} else if (isLeaf(t1) && !isLeaf(t2)) {
			return andNode(t1, t2);
		} else if (!isLeaf(t1) && isLeaf(t2)) {
			return andNode(t2, t1);
		} else {
			TreeNode *n=new TreeNode();
			n->left=treeAnd(t1->left, t2->left);
			n->right=treeAnd(t1->right, t2->right);
			return n;
		}
	}

	TreeNode* copyTree(TreeNode* root) {
		if (root==NULL) return NULL;
		TreeNode *n=new TreeNode(root->val);
		n->left=copyTree(root->left);
		n->right=copyTree(root->right);
		return n;
	}

	TreeNode* andNode(TreeNode* leaf, TreeNode* root) {
		if (leaf->val==0) return new TreeNode(0);
		else return copyTree(root);
	}

	bool isLeaf(TreeNode *n) {
		return n->left==NULL && n->right==NULL;
	}

	TreeNode* merge(TreeNode* root) {
		// post order travese;
		if (root==NULL) return NULL;
		if (root->left==NULL || root->right==NULL) return root;
		if (isLeaf(root->left) && isLeaf(root->right) &&
			root->left->val==0 && root->right->val==0) {
			return new TreeNode(0);
		}
		root->left=merge(root->left);
		root->right=merge(root->right);
		return root;
	}
};

