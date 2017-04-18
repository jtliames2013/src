199. Binary Tree Right Side View Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 74945
Total Submissions: 188569
Difficulty: Medium
Contributor: LeetCode
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search Breadth-first Search
Hide Similar Problems (M) Populating Next Right Pointers in Each Node (M) Boundary of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

1. DFS
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& res, int level) {
        if (root==NULL) return;
        if (res.size()==level) res.push_back(root->val);
        dfs(root->right, res, level+1);
        dfs(root->left, res, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};

2. BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size=q.size();
            res.push_back(q.front()->val);
            
            for (int i=0; i<size; i++) {
                TreeNode *f=q.front();
                q.pop();
                if (f->right) q.push(f->right);
                if (f->left) q.push(f->left);
            }
        }
        
        return res;
    }
};

