543. Diameter of Binary Tree Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 11144
Total Submissions: 26007
Difficulty: Easy
Contributors:
nagasupreeth
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

Subscribe to see which companies asked this question.

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
    int diameterOfBinaryTree(TreeNode* root) {
        res=0;
        dfs(root);
        return res;
    }
private:
    int dfs(TreeNode* root) {
        if (root==NULL) return 0;
        auto l=dfs(root->left), r=dfs(root->right);
        res=max(res, l+r);  // number of edges = number of nodes - 1
        return max(l, r)+1; // number of nodes
    }

    int res;
};

