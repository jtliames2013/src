98. Validate Binary Search Tree 
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3

Binary tree [1,2,3], return false.

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
    bool isValidBST(TreeNode* root, long long lower, long long upper) {
        if (root==NULL) return true;
        if (root->val<=lower || root->val>=upper) return false;
        return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};

2. Inorder
class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* &prev) {
        if (root==NULL) return true;
        if (isValidBST(root->left, prev)==false) return false;
        if (prev!=NULL && prev->val>=root->val) return false;
        prev=root;
        return isValidBST(root->right, prev);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        return isValidBST(root, prev);
    }
};

3. Iterative
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root==NULL) return true;
        TreeNode *prev=NULL, *n=root;
        stack<TreeNode*> stk;
        while (n) {
            stk.push(n);
            n=n->left;
        }
        
        while (!stk.empty()) {
            TreeNode *t=stk.top();
            stk.pop();
            if (prev!=NULL && prev->val>=t->val) return false;
            prev=t;
            n=t->right;
            while (n) {
                stk.push(n);
                n=n->left;
            }
        }
        return true;
    }
};

