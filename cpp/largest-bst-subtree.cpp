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

Lyft
|
3

Apple
|
2

Amazon
|
5

Microsoft
|
2

Google
|
3

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Element {
    int lower;
    int upper;
    int count;
    bool isBST;
    Element(int l, int u, int c, bool b):lower(l), upper(u), count(c), isBST(b) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        res=0;
        dfs(root);
        return res;
    }
private:
     Element dfs(TreeNode* root) {
         if (root==NULL) return Element(0, 0, 0, true);
         int lower=0, upper=0, count=0;
         bool isBST=false;
         Element l=dfs(root->left), r=dfs(root->right);
         if (l.isBST && r.isBST) {
             if ((l.count==0 || root->val>l.upper) &&
                 (r.count==0 || root->val<r.lower)) {
                 lower=l.count==0?root->val:l.lower;
                 upper=r.count==0?root->val:r.upper;
                 count=1+l.count+r.count;
                 isBST=true;
             }
         }

         if (isBST) res=max(res, count);
         return Element(lower, upper, count, isBST);
     }

    int res;
};

