138. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Hide Company Tags Amazon Microsoft Bloomberg Uber
Hide Tags Hash Table Linked List
Hide Similar Problems (M) Clone Graph

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head==NULL) return NULL;
        RandomListNode *newHead;
        RandomListNode *curr=head, *next;
        // duplicate node
        while (curr) {
            next=curr->next;
            RandomListNode *n=new RandomListNode(curr->label);
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

