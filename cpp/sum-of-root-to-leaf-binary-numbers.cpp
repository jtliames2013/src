1022. Sum of Root To Leaf Binary Numbers
Easy

21

36

Favorite

Share
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.

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
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        getSum(root, res, 0);        
        return res;
    }
    
    void getSum(TreeNode* node, int &res, int num) {
        if (node==NULL) return;
        if (node->left==NULL && node->right==NULL) {
            res+=num*2+node->val;
            return;
        }
        getSum(node->left, res, num*2+node->val);
        getSum(node->right, res, num*2+node->val);
    }
};
