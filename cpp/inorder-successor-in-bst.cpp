285. Inorder Successor in BST 
 Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null. 

NOTE: when curr node value is greater than p's value, mark curr node as potential successor and go left. Otherwise go right.

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *succ=NULL;
        while (root) {
            if (root->val<=p->val) {
                root=root->right;
            } else {
                succ=root;
                root=root->left;
            }
        }
        return succ;
    }
};

