102. Binary Tree Level Order Traversal Add to List
DescriptionSubmissionsSolutions
Total Accepted: 161044
Total Submissions: 421703
Difficulty: Medium
Contributor: LeetCode
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Subscribe to see which companies asked this question.

Hide Tags Tree Breadth-first Search
Hide Similar Problems (M) Binary Tree Zigzag Level Order Traversal (E) Binary Tree Level Order Traversal II (E) Minimum Depth of Binary Tree (M) Binary Tree Vertical Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int currNum=1, nextNum=0;
        vector<int> level;
        
        while (!q.empty()) {
            TreeNode* f=q.front();
            q.pop();
            currNum--;
            level.push_back(f->val);
            
            if (f->left) {
                q.push(f->left);
                nextNum++;
            }
            
            if (f->right) {
                q.push(f->right);
                nextNum++;
            }
            
            if (currNum==0) {
                currNum=nextNum;
                nextNum=0;
                res.push_back(level);
                level.clear();
            }
        }
        
        return res;
    }
};

