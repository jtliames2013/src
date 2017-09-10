Given preorder traversal array of a BST, recontruct the BST.

This can be solved in O(n) only. The approach am using is, keep a separate stack of node pointers. Push on the 1st node. Keep on traversing the preorder traversal 
1. if the value of stack top is more than the current node value, then make the current node left pointer of stack top. 
2. if the value of stack top is less that current node value, keep popping from the stack till value of stack top is more than current node. Then make current node the right child of last popped element. 
Push the current node on stack in both the cases. 

It may seem like an O(n^2) algo, but we are pushing and popping every element on stack only once so this is O(n) time and space. 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

