270. Closest Binary Search Tree Value 
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

    Given target value is a floating point.
    You are guaranteed to have only one unique value in the BST that is closest to the target.

1. Iterative
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
    int closestValue(TreeNode* root, double target) {
        if (root==NULL) return INT_MAX;
        long lower=LONG_MIN, upper=LONG_MAX;
        while (root) {
            if (root->val<target) {
                lower=root->val;
                root=root->right;
            } else {
                upper=root->val;
                root=root->left;
            }
        }
        return abs(lower-target)<abs(upper-target)?lower:upper;
    }
};

2. Recursive
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (root==NULL) return INT_MAX;
        TreeNode *n=root->val<target?root->right:root->left;
        if (n==NULL) return root->val;
        int val=closestValue(n, target);
        return abs(root->val-target)<abs(val-target)?root->val:val;
    }
};

