173. Binary Search Tree Iterator Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 84187
Total Submissions: 209419
Difficulty: Medium
Contributor: LeetCode
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Tree Stack Design
Hide Similar Problems (M) Binary Tree Inorder Traversal (M) Flatten 2D Vector (M) Zigzag Iterator (M) Peeking Iterator (M) Inorder Successor in BST

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *n=root;
        while (n) {
            stk.push(n);
            n=n->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (!hasNext()) return -1;
        TreeNode *t=stk.top();
        stk.pop();
        TreeNode *n=t->right;
        while (n) {
            stk.push(n);
            n=n->left;
        }
        return t->val;
    }
private:
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

