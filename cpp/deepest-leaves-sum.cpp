1302. Deepest Leaves Sum
Medium

7

1

Add to List

Share
Given a binary tree, return the sum of values of its deepest leaves.
 

Example 1:



Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.

Google
|
LeetCode

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
    int deepestLeavesSum(TreeNode* root) {
        if (root==NULL) return 0;
        int res=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n=q.size();
            res=0;
            for (int i=0; i<n; ++i) {
                auto f=q.front();
                q.pop();
                res+=f->val;
                
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
        }
        return res;
    }
};

