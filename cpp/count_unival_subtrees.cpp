250. Count Univalue Subtrees
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
    bool isUnival(TreeNode* root) {
        if (root==NULL) return true;
        bool l=isUnival(root->left);
        bool r=isUnival(root->right);
        if (!l || (root->left!=NULL && root->left->val!=root->val)) return false;
        if (!r || (root->right!=NULL && root->right->val!=root->val)) return false;

        count++;
        return true;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        count=0;
        isUnival(root);
        
        return count;
    }
private:
    int count;
};

