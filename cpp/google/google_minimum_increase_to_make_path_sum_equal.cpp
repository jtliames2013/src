一棵树，所有节点的value都是正整数，问只能增加某些节点值的情况下，如何调整使得从root到所有leaf的path上经过的节点值之和相等，返回增加的值的和，使这个和最小

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void maxPathSum(TreeNode* root, int sum, int& maxSum) {
		if (root==NULL) return;
		sum+=root->val;
		if (root->left==NULL && root->right==NULL) {
			maxSum=max(maxSum, sum);
			return;
		}
		maxPathSum(root->left, sum, maxSum);
		maxPathSum(root->right, sum, maxSum);
	}

	void minGap(TreeNode* root, int maxSum, int sum, int& res) {
		if (root==NULL) return;
		sum+=root->val;
		if (root->left==NULL && root->right==NULL) {
			res+=maxSum-sum;
			return;
		}
		minGap(root->left, maxSum, sum, res);
		minGap(root->right, maxSum, sum, res);
	}

	int minimumGap(TreeNode* root) {
		int maxSum=0;
		maxPathSum(root, 0, maxSum);
		int res=0;
		minGap(root, maxSum, 0, res);
		return res;
	}
};

