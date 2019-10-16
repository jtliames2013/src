117. Populating Next Right Pointers in Each Node II 
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
Hide Company Tags Microsoft Bloomberg Facebook
Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Populating Next Right Pointers in Each Node

1. Recursively
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
        if (root->left) {
            if (root->right) root->left->next=root->right;
            else {
                Node* curr=root->next;
                while (curr) {
                    if (curr->left) {
                        root->left->next=curr->left;
                        break;
                    }
                    if (curr->right) {
                        root->left->next=curr->right;
                        break;
                    }

                    curr=curr->next;
                }
            }
        }
        
        if (root->right) {
            Node* curr=root->next;
            while (curr) {
                if (curr->left) {
                    root->right->next=curr->left;
                    break;
                }
                if (curr->right) {
                    root->right->next=curr->right;
                    break;
                }

                curr=curr->next;
            }
        }
        
        connect(root->right);
        connect(root->left);
    }
};

2. Iteratively
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root==NULL) return;
        TreeLinkNode *curr=root, *head=NULL, *tail=NULL;
        while (curr) {
            while (curr) {
                if (curr->left) {
                    if (head==NULL) head=curr->left;
                    else tail->next=curr->left;                        
                    tail=curr->left;
                }
                
                if (curr->right) {
                    if (head==NULL) head=curr->right;
                    else tail->next=curr->right;                    
                    tail=curr->right;
                }
                
                curr=curr->next;
            }

            curr=head;
            head=tail=NULL; 
        }
    }
};

