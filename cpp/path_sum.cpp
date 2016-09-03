112. Path Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 117846 Total Submissions: 367843 Difficulty: Easy
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Hide Company Tags Microsoft
Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Path Sum II (H) Binary Tree Maximum Path Sum (M) Sum Root to Leaf Numbers

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

