1110. Delete Nodes And Return Forest
Medium

279

6

Favorite

Share
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

 

Example 1:



Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
 

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> st;
        for (auto d:to_delete) st.insert(d);
        dfs(root, res, st, false);
        return res;
    }
private:
    TreeNode* dfs(TreeNode* root, vector<TreeNode*>& res, unordered_set<int>& st, bool hasParent) {
        if (root==NULL) return NULL;
        bool toDelete=st.find(root->val)!=st.end();
        if (!toDelete && !hasParent) res.push_back(root);
        root->left=dfs(root->left, res, st, !toDelete);
        root->right=dfs(root->right, res, st, !toDelete);
        return toDelete?NULL:root;
    }
};
