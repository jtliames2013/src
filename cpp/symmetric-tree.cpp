101. Symmetric Tree Add to List
DescriptionSubmissionsSolutions
Total Accepted: 164349
Total Submissions: 435506
Difficulty: Easy
Contributor: LeetCode
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search Breadth-first Search

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
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (l==NULL&&r==NULL) return true;
        else if (l==NULL||r==NULL) return false;
        else {
            return l->val==r->val && isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return isSymmetric(root->left, root->right);
    }
};

