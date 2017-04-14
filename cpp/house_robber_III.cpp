337. House Robber III
 The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

     3
    / \
   2   3
    \   \ 
     3   1

Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

     3
    / \
   4   5
  / \   \ 
 1   3   1

Maximum amount of money the thief can rob = 4 + 5 = 9. 

深度优先遍历二叉树，每次遍历返回两个值：分别表示偷窃或者不偷窃当前节点可以获得的最大收益。

状态转移方程见代码。

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
  	// <max use root, max not use root>
    pair<int,int> dfs(TreeNode* root) {
        if (root==NULL) return {0,0};
        pair<int,int> l=dfs(root->left);
        pair<int,int> r=dfs(root->right);
        return {root->val+l.second+r.second, max(l.first, l.second)+max(r.first, r.second)};
    }
    
    int rob(TreeNode* root) {
        pair<int,int> res=dfs(root);
        return max(res.first, res.second);
    }
};

