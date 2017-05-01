404. Sum of Left Leaves   QuestionEditorial Solution  My Submissions
Total Accepted: 14610 Total Submissions: 32013 Difficulty: Easy Contributors: Admin
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Subscribe to see which companies asked this question

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==NULL) return 0;
        int sum=0;
        if (root->left) {
            if (root->left->left==NULL && root->left->right==NULL) sum+=root->left->val;
            else sum+=sumOfLeftLeaves(root->left);
        }
        if (root->right) {
            sum+=sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};

2. Iteratively
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==NULL) return 0;
        stack<TreeNode*> stk;
        stk.push(root);
        
        int sum=0;
        while (!stk.empty()) {
            TreeNode* t=stk.top();
            stk.pop();
            if (t->right) {
                stk.push(t->right);
            }
            if (t->left) {
                if (t->left->left==NULL && t->left->right==NULL) sum+=t->left->val;
                else stk.push(t->left);
            }
        }
        
        return sum;
    }
};

