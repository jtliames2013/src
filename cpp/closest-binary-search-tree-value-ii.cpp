272. Closest Binary Search Tree Value II  
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hide Company Tags Google
Hide Tags Tree Stack
Hide Similar Problems (M) Binary Tree Inorder Traversal (E) Closest Binary Search Tree Value

The idea is to compare the predecessors and successors of the closest node to the target, we can use two stacks to track the predecessors and successors, then like what we do in merge sort, we compare and pick the closest one to the target and put it to the result list.

As we know, inorder traversal gives us sorted predecessors, whereas reverse-inorder traversal gives us sorted successors.

We can use iterative inorder traversal rather than recursion, but to keep the code clean, here is the recursion version.

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
    void dfs(TreeNode* root, double target, stack<int>& stk, bool reverse) {
        if (root==NULL) return;
        dfs(reverse?root->right:root->left, target, stk, reverse);
        if ((reverse==false && root->val>target) || (reverse==true && root->val<=target)) return;
        stk.push(root->val);
        dfs(reverse?root->left:root->right, target, stk, reverse);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<int> pre, suc;
        dfs(root, target, pre, false);
        dfs(root, target, suc, true);
        
        while (k>0) {
            if (pre.empty()) {
                res.push_back(suc.top());
                suc.pop();
            } else if (suc.empty()) {
                res.push_back(pre.top());
                pre.pop();
            } else if (abs(pre.top()-target)<abs(suc.top()-target)) {
                res.push_back(pre.top());
                pre.pop();
            } else {
                res.push_back(suc.top());
                suc.pop();
            }
            k--;
        }
        return res;
    }
};

