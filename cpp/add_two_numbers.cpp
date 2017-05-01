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
        bool carry=false;
        
        while (l1 || l2) {
            int num=0;
            if (l1) { num+=l1->val; l1=l1->next; }
            if (l2) { num+=l2->val; l2=l2->next; }
            if (carry) {
                num++;
                carry=false;
            }
            if (num>=10) {
                num%=10;
                carry=true;
            }
            ListNode *n=new ListNode(num);
            prev->next=n;
            prev=n;
        }
        
        if (carry) {
            ListNode *n=new ListNode(1);
            prev->next=n;
        }
        
        return dummy.next;
    }
};

