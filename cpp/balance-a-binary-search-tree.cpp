1382. Balance a Binary Search Tree
Medium

8

4

Add to List

Share
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:



Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        dfs(res, root);
        return dfs2(res, 0, res.size()-1);
    }
private:
    void dfs(vector<int>& res, TreeNode* root) {
        if (root==NULL) return;
        dfs(res, root->left);
        res.push_back(root->val);
        dfs(res, root->right);
    }

    TreeNode* dfs2(vector<int>& res, int l, int r) {
        if (l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode* n=new TreeNode(res[mid]);
        n->left=dfs2(res, l, mid-1);
        n->right=dfs2(res, mid+1, r);
        return n;
    }
};

