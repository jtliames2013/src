106. Construct Binary Tree from Inorder and Postorder Traversal QuestionEditorial Solution  My Submissions
Total Accepted: 62571 Total Submissions: 208998 Difficulty: Medium
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Subscribe to see which companies asked this question

Hide Tags Tree Array Depth-first Search
Hide Similar Problems (M) Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int,int>& pos) {
        if (inStart>inEnd) return NULL;
        TreeNode* n=new TreeNode(postorder[postEnd]);
        int index=pos[postorder[postEnd]];
        n->left=buildTree(inorder, inStart, index-1, postorder, postStart, postStart+index-inStart-1, pos);
        n->right=buildTree(inorder, index+1, inEnd, postorder, postStart+index-inStart, postEnd-1, pos);
        return n;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> pos;
        for (int i=0; i<inorder.size(); i++) {
            pos[inorder[i]]=i;
        }
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, pos);
    }
};

