572. Subtree of Another Tree Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 2992
Total Submissions: 6816
Difficulty: Easy
Contributors:
xljob
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
Subscribe to see which companies asked this question.

Hide Tags Tree
Hide Similar Problems (M) Count Univalue Subtrees (M) Most Frequent Subtree Sum

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
    bool match(TreeNode* s, TreeNode* t) {
        if (s==NULL && t==NULL) return true;
        if (s!=NULL && t!=NULL) {
            return (s->val==t->val && match(s->left, t->left) && match(s->right, t->right));
        } else {
            return false;
        }
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (match(s, t)) return true;
        if (s) {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
        return false;
    }
};

