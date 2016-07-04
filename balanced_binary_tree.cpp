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

2. Use depth in return value
class Solution {
public:
    struct Element {
        bool balanced;
        int depth;
    };
    
    Element checkBalanced(TreeNode *root) {
        Element res;
        if (root==NULL) {
            res.balanced=true;
            res.depth=0;
            return res;
        }
        
        Element l=checkBalanced(root->left);
        Element r=checkBalanced(root->right);
        
        res.balanced=false;
        if (l.balanced && r.balanced && abs(l.depth-r.depth)<=1) {
            res.balanced=true;
        }
        res.depth=max(l.depth, r.depth)+1;
        
        return res;
    }
    
    bool isBalanced(TreeNode* root) {
        Element res=checkBalanced(root);
        return res.balanced;
    }
};

int main()
{
	return 0;
}

