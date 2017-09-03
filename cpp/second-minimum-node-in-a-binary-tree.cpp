671. Second Minimum Node In a Binary Tree
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.

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
    int findMin(TreeNode* node, int val) {
        if (node==NULL) return INT_MAX;
        if (node->val>val) return node->val;
        int l=findMin(node->left, val);
        int r=findMin(node->right, val);
        return min(l, r);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (root==NULL) return -1;
        int res=findMin(root, root->val);        
        return res==INT_MAX?-1:res;
    }
};

