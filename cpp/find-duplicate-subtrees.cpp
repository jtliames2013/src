652. Find Duplicate Subtrees
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.

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
    string dfs(vector<TreeNode*>& res, TreeNode* root, unordered_map<string, int>& mp) {
        if (root==NULL) return "#";
        string str=to_string(root->val)+","+dfs(res, root->left, mp)+","+dfs(res, root->right, mp);
        if (mp[str]==1) res.push_back(root);
        mp[str]++;
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> mp;
        dfs(res, root, mp);
        return res;
    }
};

