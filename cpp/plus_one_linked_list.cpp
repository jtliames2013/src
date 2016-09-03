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
        if (head==NULL) return NULL;
        //reverse
        ListNode *prev=NULL, *curr=head, *next, *tail;
        bool carry=false;
        int num;
        while (curr!=NULL) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        tail=curr=prev;
        prev=NULL;
        while (curr!=NULL) {
            if (prev==NULL) curr->val++;
            if (carry) curr->val++;
            if (curr->val>=10) {
                curr->val%=10;
                carry=true;
            } else {
                carry=false;
            }
            prev=curr;
            curr=curr->next;
        }
        
        if (carry) {
            ListNode *n=new ListNode(1);
            prev->next=n;
        }
        
        //reverse
        curr=tail;
        prev=NULL;
        while (curr!=NULL) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
};
