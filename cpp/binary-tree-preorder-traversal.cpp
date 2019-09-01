144. Binary Tree Preorder Traversal Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 171995
Total Submissions: 390601
Difficulty: Medium
Contributor: LeetCode
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Subscribe to see which companies asked this question.

Hide Tags Tree Stack
Hide Similar Problems (M) Binary Tree Inorder Traversal (M) Verify Preorder Sequence in Binary Search Tree

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode *t=stk.top();
            stk.pop();
            res.push_back(t->val);
            if (t->right) stk.push(t->right);
            if (t->left) stk.push(t->left);
        }
        
        return res;
    }
};

