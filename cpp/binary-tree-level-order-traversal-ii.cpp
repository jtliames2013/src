107. Binary Tree Level Order Traversal II Add to List
DescriptionSubmissionsSolutions
Total Accepted: 120136
Total Submissions: 309232
Difficulty: Easy
Contributor: LeetCode
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
Subscribe to see which companies asked this question.

Hide Tags Tree Breadth-first Search
Hide Similar Problems (M) Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int currNum;
        while (!q.empty()) {
            currNum=q.size();
            vector<int> level;
            for (int i=0; i<currNum; i++) {
                TreeNode* f=q.front();
                q.pop();
                level.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            res.push_back(level);
        }
        
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
};

