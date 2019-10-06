328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ... 

Note the case where even could be NULL!

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;
        ListNode *one=head, *two=head->next, *twoHead=head->next;
        ListNode *prev=NULL, *oneNext, *twoNext;
        while (one && two) {
            oneNext=two->next;
            twoNext=oneNext?oneNext->next:NULL;
            one->next=oneNext;
            two->next=twoNext;
            
            prev=one;
            one=oneNext;
            two=twoNext;
        }
        if (one) prev=one;
        prev->next=twoHead;
        
        return head;
    }
};

