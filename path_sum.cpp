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
    bool hasPathSum(TreeNode *root, int sum) {
    	if (root == NULL) return false;

    	if (root->left != NULL || root->right != NULL)
    	{
    		bool l = false, r = false;
    		if (root->left != NULL)
    			l = hasPathSum(root->left, sum - root->val);
    		if (root->right != NULL)
    			r = hasPathSum(root->right, sum - root->val);
    		return l | r;
    	}
    	else
    	{
    		return root->val == sum;
    	}
    }
};

int main()
{
	return 0;
}

