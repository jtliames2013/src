2 code: reconstruct BST from pre-order sequence.

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* dfs(vector<int>& preorder, int start, int end) {
		if (start>end) return NULL;
		TreeNode *n=new TreeNode(preorder[start]);
		int i;
		for (i=start+1; i<=end; i++) {
			if (preorder[i]>preorder[start]) break;
		}
		n->left=dfs(preorder, start+1, i-1);
		n->right=dfs(preorder, i, end);
		return n;
	}
	TreeNode* constructBST(vector<int> preorder) {
		return dfs(preorder, 0, preorder.size()-1);
	}
};

