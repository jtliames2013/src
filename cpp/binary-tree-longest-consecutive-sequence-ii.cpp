549. Binary Tree Longest Consecutive Sequence II
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
Example 2:
Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
Note: All the values of tree nodes are in the range of [-1e7, 1e7].

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
    pair<int,int> getLongest(TreeNode* root) {
        if (root==NULL) return {0,0};
        int inc=1, dec=1;
        if (root->left) {
            pair<int,int> l=getLongest(root->left);
            if (root->val==root->left->val-1) inc+=l.first;
            else if (root->val==root->left->val+1) dec+=l.second;
        }
        
        if (root->right) {
            pair<int,int> r=getLongest(root->right);
            if (root->val==root->right->val-1) inc=max(inc, r.first+1);
            else if (root->val==root->right->val+1) dec=max(dec, r.second+1);
        }
        
        len=max(len, inc+dec-1);
            
        return {inc, dec};
    }
    
    
    int longestConsecutive(TreeNode* root) {
        len=0;
        getLongest(root);
        return len;
    }
private:
    int len;
};

