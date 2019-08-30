113. Path Sum II Add to List
DescriptionSubmissionsSolutions
Total Accepted: 119091
Total Submissions: 367608
Difficulty: Medium
Contributor: LeetCode
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Path Sum (E) Binary Tree Paths (E) Path Sum III

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, res, path, sum);
        return res;
    }
private:
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum==root->val) res.push_back(path);
            path.pop_back();
            return;
        }
        
        dfs(root->left, res, path, sum-root->val);
        dfs(root->right, res, path, sum-root->val);
        path.pop_back();
    }
};
