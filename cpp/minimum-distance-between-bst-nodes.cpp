783. Minimum Distance Between BST Nodes
DescriptionHintsSubmissionsDiscussSolution
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.

1. Recursive
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
    int minDiffInBST(TreeNode* root) {
        res=INT_MAX;
        prev=INT_MIN;
        dfs(root);
        return res;
    }
    
private:
    void dfs(TreeNode* root) {
        if (root==NULL) return;
        if (root->left!=NULL) dfs(root->left);
        if (prev>INT_MIN) res=min(res, root->val-prev);
        prev=root->val;
        if (root->right!=NULL) dfs(root->right);        
    }
    
    int res;
    int prev;
};

2. Iterative
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res=INT_MAX, prev=INT_MIN;
        if (root==NULL) return res;
        stack<TreeNode*> stk;
        TreeNode *n=root;
        while (n) {
            stk.push(n);
            n=n->left;
        }
        
        while (!stk.empty()) {
            TreeNode *t=stk.top();
            stk.pop();
            if (prev>INT_MIN) res=min(res, t->val-prev);
            prev=t->val;
            n=t->right;
            while (n) {
                stk.push(n);
                n=n->left;
            }
        }
        return res;
    }
};
