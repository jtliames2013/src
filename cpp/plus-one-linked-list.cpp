369. Plus One Linked List
Medium

358

16

Favorite

Share
Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example :

Input: [1,2,3]
Output: [1,2,4]

Google
|
2

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
        ListNode *dummy=new ListNode(0), *curr=dummy, *p=dummy;
        dummy->next=head;
        while (curr) {
            if (curr->val!=9) p=curr;
            curr=curr->next;
        }
        
        p->val++;
        p=p->next;
        while (p) {
            p->val=0;
            p=p->next;
        }
        
        if (dummy->val==0) return dummy->next;
        return dummy;
    }
};

