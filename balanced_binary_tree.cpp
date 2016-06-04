#include <stdio.h>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int calHeight(TreeNode *root)
	{
		if (root == NULL) return 0;

		if (root->left == NULL && root->right == NULL)
		{
			root->val = 1;
		}
		else if (root->left == NULL)
		{
			root->val = calHeight(root->right) + 1;
		}
		else if (root->right == NULL)
		{
			root->val = calHeight(root->left) + 1;
		}
		else
		{
			int l = calHeight(root->left);
			int r = calHeight(root->right);
			root->val = l > r ? l + 1 : r + 1;
		}

		return root->val;
	}
	bool isBalanced(TreeNode *root) {
   		if (root == NULL) return true;
   		calHeight(root);

   		int l, r;
   		if (root->left == NULL) l = 0;
   		else l = root->left->val;

   		if (root->right == NULL) r = 0;
   		else r = root->right->val;

   		if (l - r <= 1 && r - l <= 1 && isBalanced(root->left) && isBalanced(root->right))
   			return true;

   		return false;
    }
};


int main()
{
	return 0;
}

