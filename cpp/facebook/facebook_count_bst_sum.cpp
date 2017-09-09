given BST and two vals(lo an hi), return sum of nodes whose val in [lo , hi]。 O(N) and O(logN) solution

1. O(n)
class Solution {
public:
	int countBSTSum(TreeNode* root, int lower, int upper) {
		if (root==NULL) return 0;
		int sum=0;
		if (root->val>upper) {
			sum=countBSTSum(root->left, lower, upper);
		} else if (root->val<lower) {
			sum=countBSTSum(root->right, lower, upper);
		} else {
			sum=root->val;
			sum+=countBSTSum(root->left, lower, root->val);
			sum+=countBSTSum(root->right, root->val, upper);
		}
		return sum;
	}
};

2. O(log(n))
struct TreeNode {
     int val;
     int sum;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x, int s) : val(x), sum(s), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countBSTSum(TreeNode* root, int lower, int upper) {
		if (root==NULL) return 0;
		TreeNode *curr=root, *prev=NULL, *next=NULL;
		while (curr) {
			if (curr->val>=lower) {
				next=curr;
				curr=curr->left;
			} else {
				prev=curr;
				curr=curr->right;
			}
		}
		// next is the first node val >= lower
		if (next==NULL) return 0;
		int l=next->sum-next->val;
		curr=root, prev=NULL, next=NULL;
		while (curr) {
			if (curr->val<=upper) {
				prev=curr;
				curr=curr->right;
			} else {
				next=curr;
				curr=curr->left;
			}
		}
		// prev is the last node val <= upper
		if (prev==NULL) return 0;
		int r=prev->sum;

		return r-l;
	}
};

