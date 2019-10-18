222. Count Complete Tree Nodes  QuestionEditorial Solution  My Submissions
Total Accepted: 38077 Total Submissions: 146866 Difficulty: Medium
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Hide Tags Tree Binary Search
Show Similar Problems

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
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        int ldepth=0, rdepth=0;
        
        TreeNode *n=root;
        while (n) {
            ldepth++;
            n=n->left;
        }
        n=root;
        while (n) {
            rdepth++;
            n=n->right;
        }
        
        if (ldepth==rdepth) return (1<<ldepth)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};

2. Iteratively
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        int res=0;
        
        while (root) {
            int ldepth=0, rdepth=0;
            res++;
            for (TreeNode *n=root->left; n!=NULL; n=n->left) ldepth++;
            for (TreeNode *n=root->right; n!=NULL; n=n->left) rdepth++;
            if (ldepth==rdepth) {
                res+=(1<<ldepth)-1;
                root=root->right;
            } else {
                res+=(1<<rdepth)-1;
                root=root->left;
            }
        }
        
        return res;
    }
};

