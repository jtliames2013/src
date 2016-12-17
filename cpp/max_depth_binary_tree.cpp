104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Hide Company Tags LinkedIn Uber Apple Yahoo
Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Balanced Binary Tree (E) Minimum Depth of Binary Tree

#include <stdio.h>
#include <vector>
#include <queue>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

int main()
{
	return 0;
}

