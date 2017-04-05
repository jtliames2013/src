100. Same Tree Add to List
DescriptionSubmissionsSolutions
Total Accepted: 191383
Total Submissions: 418246
Difficulty: Easy
Contributor: LeetCode
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL&&q==NULL) return true;
        else if (p==NULL||q==NULL) return false;
        else {
            return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

