333. Largest BST Subtree
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Hint:

You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?

Hide Company Tags Microsoft
Hide Tags Tree

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
    struct Element {
        int count;
        int lower;
        int upper;
        bool isBST;
        Element(int c, int l, int u, bool b):count(c), lower(l), upper(u), isBST(b) {}
    };
    
    Element dfs(TreeNode* node) {
        // NULL node has lower as INT_MAX and upper as INT_MIN so that a single node can have the right min and max.
        if (node==NULL) return Element(0, INT_MAX, INT_MIN, true);
        Element l=dfs(node->left);
        Element r=dfs(node->right);
        
        if (l.isBST==false || r.isBST==false || node->val<=l.upper || node->val>=r.lower) {
            return Element(max(l.count, r.count), 0, 0, false);
        }
        
        // NULL node has lower as INT_MAX and upper as INT_MIN
        return Element(l.count+r.count+1, min(l.lower, node->val), max(r.upper, node->val), true);
    }
    
    int largestBSTSubtree(TreeNode* root) {
        Element e=dfs(root);
        return e.count;
    }
};

