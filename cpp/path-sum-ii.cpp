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
    void getPath(vector<vector<int>>& res, vector<int>& path, TreeNode* node, int sum) {
        if (node==NULL) return;
        path.push_back(node->val);
        sum-=node->val;
        if (node->left==NULL&&node->right==NULL) {
            if (sum==0) res.push_back(path);
            path.pop_back();
            return;
        }
        
        if (node->left) {
            getPath(res, path, node->left, sum);
        }
        
        if (node->right) {
            getPath(res, path, node->right, sum);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        getPath(res, path, root, sum);
        
        return res;
    }
};

