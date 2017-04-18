236. Lowest Common Ancestor of a Binary Tree  
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Hide Company Tags Amazon LinkedIn Apple Facebook Microsoft
Hide Tags Tree
Hide Similar Problems (E) Lowest Common Ancestor of a Binary Search Tree

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || p==NULL || q==NULL) return NULL;
        if (root==p || root==q) return root;
        TreeNode *l=lowestCommonAncestor(root->left, p, q);
        TreeNode *r=lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        else if (l) return l;
        else if (r) return r;
        else return NULL;
    }
};

