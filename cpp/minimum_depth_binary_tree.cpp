111. Minimum Depth of Binary Tree  
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Hide Tags Tree Depth-first Search Breadth-first Search
Hide Similar Problems (E) Binary Tree Level Order Traversal (E) Maximum Depth of Binary Tree

#include <stdio.h>
#include <vector>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int depth;
        if (root->left==NULL && root->right==NULL) depth=1;
        else if (root->left==NULL) {
            depth=minDepth(root->right)+1;
        } else if (root->right==NULL) {
            depth=minDepth(root->left)+1;
        } else {
            depth=min(minDepth(root->left), minDepth(root->right))+1;
        }
        
        return depth;
    }
};

int main()
{
	return 0;
}

