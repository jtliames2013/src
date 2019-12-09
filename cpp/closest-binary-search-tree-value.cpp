270. Closest Binary Search Tree Value
Easy

513

38

Favorite

Share
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4

Facebook
|
10

Amazon
|
4

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
        long lower=LONG_MIN, upper=LONG_MAX;
        while (root) {
            if (target<root->val) {
                upper=root->val;
                root=root->left;
            } else {
                lower=root->val;
                root=root->right;
            }
        }
        return abs(lower-target)<abs(upper-target)?lower:upper;
    }
};

2. Recursive
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* n=(target<root->val)?root->left:root->right;
        if (n==NULL) return root->val;
        int val=closestValue(n, target);
        return abs(val-target)<abs(root->val-target)?val:root->val;
    }
};

