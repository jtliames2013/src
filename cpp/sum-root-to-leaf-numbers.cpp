129. Sum Root to Leaf Numbers  QuestionEditorial Solution  My Submissions
Total Accepted: 87140 Total Submissions: 256129 Difficulty: Medium
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Subscribe to see which companies asked this question

Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Path Sum (H) Binary Tree Maximum Path Sum

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
    int sumNumbers(TreeNode* root) {
        int res=0, num=0;
        dfs(root, res, num);
        return res;
    }
private:
    void dfs(TreeNode* root, int& res, int num) {
        if (root==NULL) return;
        num=num*10+root->val;
        if (root->left==NULL && root->right==NULL) {
            res+=num;
            return;
        }
        dfs(root->left, res, num);
        dfs(root->right, res, num);
    }
};
