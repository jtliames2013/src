538. Convert BST to Greater Tree Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 7233
Total Submissions: 13785
Difficulty: Medium
Contributors:
love_Fawn
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
Subscribe to see which companies asked this question.

Hide Tags Tree

1. Iteratively
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
    TreeNode* convertBST(TreeNode* root) {
        if (root==NULL) return root;
        stack<TreeNode*> stk;
        int sum=0;
        TreeNode* n=root;
        while (n) {
            stk.push(n);
            n=n->right;
        }
        
        while (!stk.empty()) {
            TreeNode* t=stk.top();
            stk.pop();
            t->val+=sum;
            sum=t->val;
            n=t->left;
            while (n) {
                stk.push(n);
                n=n->right;
            }
        }
        
        return root;
    }
};

2. Recursively
class Solution {
public:
    void dfs(TreeNode* root, int& sum) {
        if (root==NULL) return;
        dfs(root->right, sum);
        root->val+=sum;
        sum=root->val;
        dfs(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        dfs(root, sum);
        
        return root;
    }
};

