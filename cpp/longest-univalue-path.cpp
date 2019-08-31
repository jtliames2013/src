687. Longest Univalue Path
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int res=INT_MIN;
        dfs(root, res);
        
        return res;
    }

private:
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        int l=dfs(root->left, res);
        int r=dfs(root->right, res);
        if (root->left && root->left->val==root->val) l++;
        else l=0;
        if (root->right && root->right->val==root->val) r++;
        else r=0;
        
        res=max(res, l+r);
        
        return max(l, r);
    }
};
