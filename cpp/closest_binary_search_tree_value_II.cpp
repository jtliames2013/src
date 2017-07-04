272. Closest Binary Search Tree Value II  
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hint:

Consider implement these two helper functions:
getPredecessor(N), which returns the next smaller node to N.
getSuccessor(N), which returns the next larger node to N.
Try to assume that each node has a parent pointer, it makes the problem much easier.
Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
You would need two stacks to track the path in finding predecessor and successor node separately.
Hide Company Tags Google
Hide Tags Tree Stack
Hide Similar Problems (M) Binary Tree Inorder Traversal (E) Closest Binary Search Tree Value

  class Solution {
public:
    long long getPredecessor(stack<TreeNode*>& small) {
        if(!small.empty()) {
            TreeNode *n=small.top();
            small.pop();
            TreeNode *node=n->left;
            while (node!=NULL) {
                small.push(node);
                node=node->right;
            }
            return n->val;
        } else {
            return LLONG_MIN;
        }
    }

    long long getSuccessor(stack<TreeNode*>& large) {
        if (!large.empty()) {
            TreeNode *n=large.top();
            large.pop();
            TreeNode *node=n->right;
            while (node!=NULL) {
                large.push(node);
                node=node->left;
            }
            return n->val;
        } else {
            return LLONG_MAX;
        }
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> small, large;
        while (root!=NULL) {
            if (root->val>target) {
                large.push(root);
                root=root->left;
            } else {
                small.push(root);
                root=root->right;
            }
        }

        long long s, l;
        s=getPredecessor(small);
        l=getSuccessor(large);

        for (int i=0; i<k; i++) {
            if (abs(target-s)<abs(l-target)) {
                res.push_back(s);
                s=getPredecessor(small);
            } else {
                res.push_back(l);
                l=getSuccessor(large);
            }
        }

        return res;
    }
};

