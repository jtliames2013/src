9
Easy

5

0

Favorite

Share
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

1. DFS
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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<int,int>> mp;
        dfs(root, 0, 0, mp);
        return mp[x].first!=mp[y].first && mp[x].second==mp[y].second;
    }
    
    void dfs(TreeNode* root, int parent, int depth, unordered_map<int, pair<int,int>>& mp) {
        if (!root) return;
        mp[root->val]={parent, depth};
        dfs(root->left, root->val, depth+1, mp);
        dfs(root->right, root->val, depth+1, mp);
    }
};

2. BFS
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n=q.size();
            bool found=false;
            int parent=0;            
            for (int i=0; i<n; ++i) {
                auto f=q.front();
                q.pop();                
                if (f.first->val==x||f.first->val==y) {                    
                    if (!found) {
                        found=true;
                        parent=f.second;
                        cout << parent << endl;
                    } else {
                        return parent!=f.second;
                    }
                }
                
                if (f.first->left) q.push({f.first->left, f.first->val});
                if (f.first->right) q.push({f.first->right, f.first->val});
            }
            if (found) return false;
        }
        
        return false;
    }
};

