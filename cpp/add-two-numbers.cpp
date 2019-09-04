2. Add Two Numbers 
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Hide Company Tags Amazon Microsoft Bloomberg Airbnb Adobe
Hide Tags Linked List Math
Hide Similar Problems (M) Multiply Strings (E) Add Binary (E) Sum of Two Integers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *prev=&dummy;
        int num=0;
        
        while (l1 || l2) {
            if (l1) { num+=l1->val; l1=l1->next; }
            if (l2) { num+=l2->val; l2=l2->next; }
            ListNode *n=new ListNode(num%10);
            num/=10;
            prev->next=n;
            prev=n;
        }
        
        if (num!=0) {            
            prev->next=new ListNode(num);
        }
        
        return dummy.next;
    }
};
