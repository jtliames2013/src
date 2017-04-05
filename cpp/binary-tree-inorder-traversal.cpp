94. Binary Tree Inorder Traversal Add to List
DescriptionSubmissionsSolutions
Total Accepted: 188099
Total Submissions: 417577
Difficulty: Medium
Contributor: LeetCode
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

Subscribe to see which companies asked this question.

Hide Tags Tree Hash Table Stack
Hide Similar Problems (M) Validate Binary Search Tree (M) Binary Tree Preorder Traversal (H) Binary Tree Postorder Traversal (M) Binary Search Tree Iterator (M) Kth Smallest Element in a BST (H) Closest Binary Search Tree Value II (M) Inorder Successor in BST

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* n=root;
        while (n) {
            stk.push(n);
            n=n->left;
        }
        while (!stk.empty()) {
            n=stk.top();
            res.push_back(n->val);
            stk.pop();
            
            n=n->right;
            while (n) {
                stk.push(n);
                n=n->left;
            }
        }
        
        return res;
    }
};

