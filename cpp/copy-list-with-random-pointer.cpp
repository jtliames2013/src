138. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Hide Company Tags Amazon Microsoft Bloomberg Uber
Hide Tags Hash Table Linked List
Hide Similar Problems (M) Clone Graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL) return NULL;
        Node *newHead, *curr=head, *next;

        // duplicate node
        while (curr) {
            next=curr->next;
            Node *n=new Node(curr->val);
            curr->next=n;
            n->next=next;
            curr=next;
        }
        
        // duplicate random pointer
        curr=head;
        while (curr) {
            curr->next->random=curr->random?curr->random->next:NULL;
            curr=curr->next->next;
        }
        
        // separate the list
        curr=head;
        newHead=curr->next;
        while (curr) {
            next=curr->next->next;
            curr->next->next=next?next->next:NULL;
            curr->next=next;
            curr=next;
        }
        return newHead;
    }
};
