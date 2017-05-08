513. Find Bottom Left Tree Value Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 14161
Total Submissions: 25426
Difficulty: Medium
Contributors:
abhijeet17
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.

Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search Breadth-first Search

1. BFS
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* f;
        while (!q.empty()) {
            f=q.front();
            q.pop();

            // right to left at each level            
            if (f->right) q.push(f->right);
            if (f->left) q.push(f->left);
        }
        
        return f->val;
    }
};

2. DFS
class Solution {
public:
    void findBottomLeftValue(TreeNode* root, int depth) {
        if (depth>maxDepth) {
            maxDepth=depth;
            res=root->val;
        }
        
        if (root->left) findBottomLeftValue(root->left, depth+1);
        if (root->right) findBottomLeftValue(root->right, depth+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        maxDepth=0;
        res=0;
        findBottomLeftValue(root, 1);
        return res;
    }
private:
     int maxDepth;
     int res;
};

