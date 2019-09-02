105. Construct Binary Tree from Preorder and Inorder Traversal  QuestionEditorial Solution  My Submissions
Total Accepted: 72257 Total Submissions: 243466 Difficulty: Medium
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Subscribe to see which companies asked this question

Hide Tags Tree Array Depth-first Search
Hide Similar Problems (M) Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& pos) {
        if (preStart>preEnd) return NULL;
        TreeNode* n=new TreeNode(preorder[preStart]);
        int index=pos[preorder[preStart]];
        n->left=buildTree(preorder, preStart+1, preStart+index-inStart, inorder, inStart, index-1, pos);
        n->right=buildTree(preorder, preStart+index-inStart+1, preEnd, inorder, index+1, inEnd, pos);
        return n;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> pos;
        for (int i=0; i<inorder.size(); i++) {
            pos[inorder[i]]=i;
        }
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, pos);
    }
};

