450. Delete Node in a BST Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 13961
Total Submissions: 38956
Difficulty: Medium
Contributors:
tsipporah5945
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
Subscribe to see which companies asked this question.

Hide Tags Tree

1. Recursively
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;
        if (root->val>key) {
            root->left=deleteNode(root->left, key);
        } else if (root->val<key) {
            root->right=deleteNode(root->right, key);
        } else {
            if (root->left==NULL) {
                TreeNode* r=root->right;
                delete root;
                return r;
            } else if (root->right==NULL) {
                TreeNode* l=root->left;
                delete root;
                return l;
            } else {
                TreeNode* curr=root->right;
                while (curr->left) curr=curr->left;
                root->val=curr->val;
                root->right=deleteNode(root->right, curr->val);
            }
        }
        return root;
    }
};

2. Iteratively
class Solution {
public:
    TreeNode* deleteRoot(TreeNode* root) {
        if (root==NULL) return NULL;
        if (root->left==NULL) {
            TreeNode *r=root->right;
            delete root;
            return r;
        } else if (root->right==NULL) {
            TreeNode *l=root->left;
            delete root;
            return l;
        } else {
            TreeNode *curr=root->right, *prev=NULL;
            while (curr->left) {
                prev=curr;
                curr=curr->left;
            }
            curr->left=root->left;
            if (prev){
                prev->left=curr->right;
                curr->right=root->right;
            }
            delete root;
            return curr;
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *curr=root, *prev=NULL;
        while (curr) {
            if (curr->val==key) break;
            prev=curr;
            if (curr->val>key) curr=curr->left;
            else curr=curr->right;
        }
        
        if (prev==NULL) {
            return deleteRoot(curr);
        } else if (prev->left==curr) {
            prev->left=deleteRoot(curr);
        } else {
            prev->right=deleteRoot(curr);
        }
        return root;
    }
};

