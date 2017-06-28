369. Plus One Linked List 
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
Hide Company Tags Google
Hide Tags Linked List
Hide Similar Problems (E) Plus One

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
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=NULL, *curr=dummy, *p=dummy;
        while (curr) {
            if (curr->val!=9) p=curr;
            prev=curr;
            curr=curr->next;
        }
        if (prev->val!=9) prev->val++;
        else {
            p->val++;
            p=p->next;
            while (p) {
                p->val=0;
                p=p->next;
            }
        }
        if (dummy->val==0) return dummy->next;
        return dummy;
    }
};

