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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (!root || root==p || root==q)  return root;
    	TreeNode* left = lowestCommonAncestor(root->left, p, q);
    	TreeNode* right = lowestCommonAncestor(root->right, p, q);
    	if (left && right) return root;
    	else if (left) return left;
    	else if (right) return right;
    	else return NULL;
    }
};

2.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || p==root || q==root) return root;
        TreeNode *l=lowestCommonAncestor(root->left, p, q);
        TreeNode *r=lowestCommonAncestor(root->right, p, q);
        if (l==NULL) return r;
        if (r==NULL) return l;
        return root;
    }
};

int main()
{
	return 0;
}


