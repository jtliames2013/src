116. Populating Next Right Pointers in Each Node Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 125975
Total Submissions: 341274
Difficulty: Medium
Contributor: LeetCode
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,

Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Populating Next Right Pointers in Each Node II (M) Binary Tree Right Side View

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
     }
private:
    void dfs(Node* root) {
        if (root==NULL) return;
        if (root->left==NULL && root->right==NULL) return;
        root->left->next=root->right;
        root->right->next=root->next?root->next->left:NULL;
        connect(root->left);
        connect(root->right);
    }
};
