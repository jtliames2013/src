1026. Maximum Difference Between Node and Ancestor
Medium

211

11

Favorite

Share
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

Example 1:



Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 

Note:

The number of nodes in the tree is between 2 and 5000.
Each node will have value between 0 and 100000.

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
    int maxAncestorDiff(TreeNode* root) {
        int res=0;
        dfs(root, res);
        return res;
    }
private:
    pair<int,int> dfs(TreeNode* root, int& res) {
        if (root==NULL) return {0, 0};
        int mn=root->val, mx=root->val;
        if (root->left) {
            auto l=dfs(root->left, res);
            res=max(res, max(abs(root->val-l.first), abs(root->val-l.second)));
            mn=min(mn, l.first);
            mx=max(mx, l.second);
        }
        if (root->right) {
            auto r=dfs(root->right, res);
            res=max(res, max(abs(root->val-r.first), abs(root->val-r.second)));
            mn=min(mn, r.first);
            mx=max(mx, r.second);
        }
        return {mn, mx};
    }
};
