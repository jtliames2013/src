114. Flatten Binary Tree to Linked List  
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

Hide Company Tags Microsoft
Hide Tags Tree Depth-first Search

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
    void flatten(TreeNode* root, TreeNode** head, TreeNode** tail) {
        if (root==NULL) return;
        *head=*tail=root;
        // Remember right child first
        TreeNode *r=root->right;
        
        if (root->left) {
            TreeNode *leftHead=NULL, *leftTail=NULL;
            flatten(root->left, &leftHead, &leftTail);
            root->right=leftHead;
            *tail=leftTail;
            root->left=NULL;
        }
        
        if (r) {
            TreeNode *rightHead=NULL, *rightTail=NULL;
            flatten(r, &rightHead, &rightTail);
            (*tail)->right=rightHead;
            *tail=rightTail;
        }
    }
    void flatten(TreeNode* root) {
        TreeNode *head=NULL, *tail=NULL;
        return flatten(root, &head, &tail);
    }
};

