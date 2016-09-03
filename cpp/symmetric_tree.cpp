#include <stdio.h>
#include <vector>
#include <queue>

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
	bool isTwoSymmetric(TreeNode *l, TreeNode *r)
	{
		if (l == NULL && r == NULL)
		{
			return true;
		}
		else if (l == NULL || r == NULL)
		{
			return false;
		}
		else
		{
			return ((l->val == r->val) && isTwoSymmetric(l->left, r->right) && isTwoSymmetric(l->right, r->left));
		}
	}

    bool isSymmetric(TreeNode *root) {
    	if (root == NULL) return true;

   		return isTwoSymmetric(root->left, root->right);
    }
};

int main()
{
	return 0;
}

