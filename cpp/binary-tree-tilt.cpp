563. Binary Tree Tilt Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 5574
Total Submissions: 11599
Difficulty: Easy
Contributors:
fallcreek
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.
Subscribe to see which companies asked this question.

Hide Tags Tree

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
        if (root==NULL) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        tilt+=abs(l-r);
        return l+r+root->val;
    }
    
    int findTilt(TreeNode* root) {
        tilt=0;
        dfs(root);
        return tilt;
    }
private:
    int tilt;
};

2.
class Solution {
public:
    pair<int,int> dfs(TreeNode* root) {
        if (root==NULL) return {0,0};
        pair<int,int> l=dfs(root->left);
        pair<int,int> r=dfs(root->right);
        return {l.first+r.first+root->val, abs(l.first-r.first)+l.second+r.second};
    }
    
    int findTilt(TreeNode* root) {
        pair<int,int> res=dfs(root);
        return res.second;
    }
};

