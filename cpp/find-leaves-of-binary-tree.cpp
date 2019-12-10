366. Find Leaves of Binary Tree
Medium

780

11

Favorite

Share
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

 

Example:

Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

Output: [[4,5,3],[2],[1]]
 

Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         / 
        2          
 

2. Now removing the leaf [2] would result in this tree:

          1          
 

3. Now removing the leaf [1] would result in the empty tree:

          []         

LinkedIn
|
10

Atlassian
|
2


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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root);
        
        return res;
    }
private:
    int dfs(vector<vector<int>>& res, TreeNode* root) {
        if (root==NULL) return 0;
        int depth=1+max(dfs(res, root->left), dfs(res, root->right));
        if (depth>res.size()) res.resize(depth);
        res[depth-1].push_back(root->val);
        return depth;
    }
};

