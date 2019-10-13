971. Flip Binary Tree To Match Preorder Traversal
Medium

150

73

Favorite

Share
Given a binary tree with N nodes, each node has a different value from {1, ..., N}.

A node in this binary tree can be flipped by swapping the left child and the right child of that node.

Consider the sequence of N values reported by a preorder traversal starting from the root.  Call such a sequence of N values the voyage of the tree.

(Recall that a preorder traversal of a node means we report the current node's value, then preorder-traverse the left child, then preorder-traverse the right child.)

Our goal is to flip the least number of nodes in the tree so that the voyage of the tree matches the voyage we are given.

If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.

If we cannot do so, then return the list [-1].

 

Example 1:



Input: root = [1,2], voyage = [2,1]
Output: [-1]
Example 2:



Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]
Example 3:



Input: root = [1,2,3], voyage = [1,2,3]
Output: []
 

Note:

1 <= N <= 100

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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        int i=0;
        if (dfs(root, voyage, res, i)) return res;
        else return {-1};        
    }
private:
    bool dfs(TreeNode* root, vector<int>&  voyage, vector<int>& res, int& index) {
        if (root==NULL) return true;
        if (root->val!=voyage[index++]) return false;
        if (root->left && root->left->val!=voyage[index]) {
            res.push_back(root->val);
            return dfs(root->right, voyage, res, index) && dfs(root->left, voyage, res, index);
        }
        return dfs(root->left, voyage, res, index) && dfs(root->right, voyage, res, index);
    }
};
