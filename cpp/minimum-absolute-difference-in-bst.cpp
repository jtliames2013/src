530. Minimum Absolute Difference in BST Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 11185
Total Submissions: 23489
Difficulty: Easy
Contributors:
nagasupreeth
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.

Subscribe to see which companies asked this question.

Hide Tags Binary Search Tree
Hide Similar Problems (E) K-diff Pairs in an Array

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
    int getMinimumDifference(TreeNode* root) {
        int diff=INT_MAX, prev=-1;
        stack<TreeNode*> stk;
        TreeNode* n=root;
        while (n) {
            stk.push(n);
            n=n->left;
        }
        
        while (!stk.empty()) {
            TreeNode* t=stk.top();
            stk.pop();
            if (prev>=0) diff=min(diff, t->val-prev);
            prev=t->val;
            
            n=t->right;
            while (n) {
                stk.push(n);
                n=n->left;
            }
        }
        
        return diff;
    }
};

