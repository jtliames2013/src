366. Find Leaves of Binary Tree 
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         / 
        2          
2. Now removing the leaf [2] would result in this tree:

          1          
3. Now removing the leaf [1] would result in the empty tree:

          []         
Returns [4, 5, 3], [2], [1].

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

Hide Company Tags LinkedIn
Hide Tags Tree Depth-first Search

class Solution {
public:
    int dfs(TreeNode *root, vector<vector<int>>& res) {
        if (root==NULL) return 0;
        int depth=max(dfs(root->left, res), dfs(root->right, res))+1;
        if (depth>res.size()) res.resize(depth);
        res[depth-1].push_back(root->val);
        return depth;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        
        return res;
    }
};

2.
下面这种DFS方法没有用计算深度的方法，而是使用了一层层剥离的方法，思路是遍历二叉树，找到叶节点，将其赋值为NULL，然后加入leaves数组中，这样一层层剥洋葱般的就可以得到最终结果了：
class Solution {
public:
    TreeNode* remove(TreeNode *root, vector<int>& leaves) {
        if (root==NULL) return NULL;
        if (root->left==NULL && root->right==NULL) {
            leaves.push_back(root->val);
            return NULL;
        }
        
        root->left=remove(root->left, leaves);
        root->right=remove(root->right, leaves);
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root) {
            vector<int> leaves;
            root=remove(root, leaves);
            res.push_back(leaves);
        }       
        return res;
    }
};
