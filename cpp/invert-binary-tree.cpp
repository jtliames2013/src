226. Invert Binary Tree Add to List
DescriptionSubmissionsSolutions
Total Accepted: 161714
Total Submissions: 318904
Difficulty: Easy
Contributor: LeetCode
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
Subscribe to see which companies asked this question.

Hide Tags Tree

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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) return NULL;
        TreeNode *l=root->left;
        TreeNode *r=root->right;
        root->left=invertTree(r);
        root->right=invertTree(l);
        return root;
    }
};

