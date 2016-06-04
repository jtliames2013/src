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
    int maxDepth(TreeNode *root) {
    	if (root == NULL) return 0;

    	if (root->left == NULL && root->right == NULL)
    	{
    		return 1;
    	}
    	else if (root->left == NULL)
    	{
    		return 1 + maxDepth(root->right);
    	}
    	else if (root->right == NULL)
    	{
    		return 1 + maxDepth(root->left);
    	}
    	else
    	{
    		int l = maxDepth(root->left);
    		int r = maxDepth(root->right);
    		return l > r ? l + 1: r + 1;
    	}
    }
};

int main()
{
	return 0;
}

