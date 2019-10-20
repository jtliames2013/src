19. Remove Nth Node From End of List  QuestionEditorial Solution  My Submissions
Total Accepted: 134596 Total Submissions: 429793 Difficulty: Easy
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Subscribe to see which companies asked this question

Hide Tags Linked List Two Pointers

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL) return NULL;
        ListNode dummy(0);
        dummy.next=head;
        ListNode *curr=head, *prev=&dummy, *tail=head;
        while (n-- > 0) {
            tail=tail->next;
        }

        while (tail) {
            prev=curr;
            curr=curr->next;
            tail=tail->next;
        }
        
        prev->next=curr->next;
        delete curr;
        return dummy.next;
    }
};
