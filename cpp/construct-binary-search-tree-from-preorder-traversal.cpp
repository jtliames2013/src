1008. Construct Binary Search Tree from Preorder Traversal
Medium

343

13

Favorite

Share
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return dfs(preorder, i, INT_MAX);        
    }
private:
    TreeNode* dfs(vector<int>& preorder, int& i, int bound) {
        if (i==preorder.size() || preorder[i]>bound) return NULL;
        TreeNode *n=new TreeNode(preorder[i++]);
        n->left=dfs(preorder, i, n->val);
        n->right=dfs(preorder, i, bound);
        return n;
    }
};
