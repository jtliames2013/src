701. Insert into a Binary Search Tree
Medium

436

50

Favorite

Share
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==NULL) return new TreeNode(val);        
        TreeNode* curr=root;
        while (curr) {
            if (curr->val<val) {
                if (curr->right==NULL) {
                    curr->right=new TreeNode(val);
                    break;
                } else {
                    curr=curr->right;
                }
            } else if (curr->val>val) {
                if (curr->left==NULL) {                    
                    curr->left=new TreeNode(val);
                    break;
                } else {
                    curr=curr->left;
                }
            }
        }
        return root;
    }
};
