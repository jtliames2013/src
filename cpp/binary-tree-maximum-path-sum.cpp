124. Binary Tree Maximum Path Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 69809 Total Submissions: 292376 Difficulty: Hard
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

Hide Company Tags Microsoft
Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Path Sum (M) Sum Root to Leaf Numbers

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
    int dfs(TreeNode* root, int& sum) {
        if (root==NULL) return 0;
        int l=dfs(root->left, sum);
        int r=dfs(root->right, sum);
        sum=max(sum, max(l, 0)+max(r, 0)+root->val);
        
        return max(0, max(l, r))+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if (root==NULL) return 0;
        int sum=INT_MIN;
        dfs(root, sum);
        return sum;
    }
};

