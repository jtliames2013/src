426. Convert Binary Search Tree to Sorted Doubly Linked List
Medium

625

70

Favorite

Share
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

 

Example 1:



Input: root = [4,2,5,1,3]


Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

Example 2:

Input: root = [2,1,3]
Output: [1,2,3]
Example 3:

Input: root = []
Output: []
Explanation: Input is an empty tree. Output is also an empty Linked List.
Example 4:

Input: root = [1]
Output: [1]
 

Constraints:

-1000 <= Node.val <= 1000
Node.left.val < Node.val < Node.right.val
All values of Node.val are unique.
0 <= Number of Nodes <= 2000

Facebook
|
24

Amazon
|
4

Lyft
|
3

Databricks
|
2

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node *head=NULL, *tail=NULL;
        dfs(root, &head, &tail);
        return head;
    }
private:
    void dfs(Node* root, Node** head, Node** tail) {
        if (root==NULL) return;
        *head=*tail=root;
        if (root->left) {
            Node *lh=NULL, *lt=NULL;
            dfs(root->left, &lh, &lt);
            *head=lh;
            lt->right=root;
            root->left=lt;
        }
        if (root->right) {
            Node *rh=NULL, *rt=NULL;
            dfs(root->right, &rh, &rt);
            *tail=rt;
            rh->left=root;
            root->right=rh;
        }
        (*head)->left=*tail;
        (*tail)->right=*head;        
    }
};

