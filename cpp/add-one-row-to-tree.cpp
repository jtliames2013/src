623. Add One Row to Tree
DescriptionHintsSubmissionsSolutions
Total Accepted: 2029
Total Submissions: 4056
Difficulty: Medium
Contributors:
fallcreek
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.

Example 1:
Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

Example 2:
Input: 
A binary tree as following:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

Output: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1
Note:
The given d is in range [1, maximum depth of the given tree + 1].
The given binary tree has at least one tree node.
Subscribe to see which companies asked this question.

Hide Tags Tree

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
    void dfs(TreeNode *n, int v, int d, int depth) {
        if (depth==d-1) {
            TreeNode *l=new TreeNode(v);
            l->left=n->left;
            n->left=l;
            TreeNode *r=new TreeNode(v);
            r->right=n->right;
            n->right=r;
            return;
        }
        if (n->left) dfs(n->left, v, d, depth+1);
        if (n->right) dfs(n->right, v, d, depth+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1) {
            TreeNode *n=new TreeNode(v);
            n->left=root;
            return n;
        }
        
        dfs(root, v, d, 1);
        return root;
    }
};

2. BFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1) {
            TreeNode *n=new TreeNode(v);
            n->left=root;
            return n;
        }
        queue<TreeNode*> q;
        int depth=1;
        q.push(root);
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; i++) {
                TreeNode *f=q.front();
                q.pop();
                if (depth==d-1) {
                    TreeNode *l=new TreeNode(v);
                    l->left=f->left;
                    f->left=l;
                    TreeNode *r=new TreeNode(v);
                    r->right=f->right;
                    f->right=r;
                } else {
                    if (f->left) q.push(f->left);
                    if (f->right) q.push(f->right);
                }
            }
            depth++;
        }

        return root;
    }
};

