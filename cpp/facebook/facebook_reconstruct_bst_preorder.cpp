2 code: reconstruct BST from pre-order sequence.

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* constructTree(vector<int> preorder) {
		int n=preorder.size();
		if (n==0) return NULL;
		stack<TreeNode*> stk;
		TreeNode *root=new TreeNode(preorder[0]);
		stk.push(root);
		for (int i=1; i<n; i++) {
			TreeNode *n=new TreeNode(preorder[i]);
			if (stk.top()->val > n->val) {
				stk.top()->left=n;
			} else {
				TreeNode *last;
				while (!stk.empty() && stk.top()->val < n->val) {
					last=stk.top();
					stk.pop();
				}
				last->right=n;
			}
			stk.push(n);
		}
		return root;
	}
};

2. Recursive
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

void print(TreeNode *root) {
	if (root==NULL) return;
	print(root->left);
	cout << root->val << endl;
	print(root->right);
}

int main()
{
	Solution s;
	vector<int> nums={4, 2, 1, 3, 6, 5, 7};
	TreeNode *root=s.constructTree(nums);
	print(root);
	return 0;
}

