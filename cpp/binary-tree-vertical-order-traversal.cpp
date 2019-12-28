314. Binary Tree Vertical Order Traversal  
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7

return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]

Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
Hide Company Tags Google Snapchat Facebook
Hide Tags Hash Table
Hide Similar Problems (E) Binary Tree Level Order Traversal

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
    void getBound(TreeNode* root, int index) {
        if (root==NULL) return;
        l=min(l, index);
        r=max(r, index);
        getBound(root->left, index-1);
        getBound(root->right, index+1);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root==NULL) return vector<vector<int>>();
        l=INT_MAX;
        r=INT_MIN;
        getBound(root, 0);
        vector<vector<int>> res(r-l+1, vector<int>());
        queue<pair<TreeNode*, int>> q;
        q.push({root, -l});
        
        while (!q.empty()) {
            pair<TreeNode*,int> f=q.front();
            q.pop();
            res[f.second].push_back(f.first->val);
            if (f.first->left) q.push({f.first->left, f.second-1});
            if (f.first->right) q.push({f.first->right, f.second+1});
        }
        
        return res;
    }
private:
    int l;
    int r;
};

