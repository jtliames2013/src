111. Minimum Depth of Binary Tree  
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Hide Tags Tree Depth-first Search Breadth-first Search
Hide Similar Problems (E) Binary Tree Level Order Traversal (E) Maximum Depth of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        if (root->left==NULL&&root->right==NULL) return 1;
        int depth=INT_MAX;
        if (root->left) {
            depth=min(depth,minDepth(root->left)+1);
        }
        if (root->right) {
            depth=min(depth,minDepth(root->right)+1);
        }
        return depth;
    }
};

