110. Balanced Binary Tree Add to List
DescriptionSubmissionsSolutions
Total Accepted: 163411
Total Submissions: 444955
Difficulty: Easy
Contributor: LeetCode
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Maximum Depth of Binary Tree

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
    int dfs(TreeNode* root) {
        // return depth if balanced. otherwise return -1
        if (root==NULL) return 0;
        int l=dfs(root->left);
        if (l==-1) return -1;
        int r=dfs(root->right);
        if (r==-1) return -1;
        return abs(l-r)<=1 ? max(l,r)+1 : -1;
    }
    
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};

