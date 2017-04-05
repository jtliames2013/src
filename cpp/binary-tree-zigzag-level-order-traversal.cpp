103. Binary Tree Zigzag Level Order Traversal  QuestionEditorial Solution  My Submissions
Total Accepted: 67955 Total Submissions: 226918 Difficulty: Medium
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        stack<TreeNode*> stk1, stk2;
        vector<int> level;
        stk1.push(root);
        
        while (!stk1.empty()) {
            while (!stk1.empty()) {
                TreeNode* t=stk1.top();
                level.push_back(t->val);
                stk1.pop();
                if (t->left) stk2.push(t->left);
                if (t->right) stk2.push(t->right);
            }
            if (!level.empty()) {
                res.push_back(level);
                level.clear();
            }
            
            while (!stk2.empty()) {
                TreeNode* t=stk2.top();
                level.push_back(t->val);
                stk2.pop();
                if (t->right) stk1.push(t->right);
                if (t->left) stk1.push(t->left);
            }
            if (!level.empty()) {
                res.push_back(level);
                level.clear();
            }
        }
        
        return res;
    }
};

