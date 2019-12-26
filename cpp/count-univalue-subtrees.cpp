2
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,

              5
             / \
            1   5
           / \   \
          5   5   5

return 4. 

Box
|
4

Bloomberg
|
2

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
    int countUnivalSubtrees(TreeNode* root) {
        count=0;
        isUnival(root);
        return count;
    }
private:
    bool isUnival(TreeNode* root) {
        if (root==NULL) return true;
        bool l=root->left==NULL || (isUnival(root->left) && root->val==root->left->val);
        bool r=root->right==NULL || (isUnival(root->right) && root->val==root->right->val);
        if (l && r) {
            count++;
            return true;
        }
        return false;
    }

    int count;
};

