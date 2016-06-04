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
    int minDepth(TreeNode *root) {
    	if (root == NULL) return 0;

    	if (root->left == NULL && root->right == NULL)
    		return 1;
    	else
    	{
			int l=0x7fffffff,r=0x7fffffff;
			if (root->left != NULL) l = minDepth(root->left) + 1;
			if (root->right != NULL) r = minDepth(root->right) + 1;
			return l < r ? l : r;
    	}
    }
};

int main()
{
	return 0;
}

