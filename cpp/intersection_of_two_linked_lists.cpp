160. Intersection of Two Linked Lists Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 123163
Total Submissions: 406862
Difficulty: Easy
Contributor: LeetCode
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Linked List

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) return NULL;
        ListNode *a=headA, *b=headB;
        int alen=0, blen=0;

        while (a!=NULL) { alen++; a=a->next; }
        while (b!=NULL) { blen++; b=b->next; }
        
        a=headA;
        b=headB;
        if (alen>blen) {
            while (alen>blen) { alen--; a=a->next; }
        } else if (blen>alen) {
            while (blen>alen) { blen--; b=b->next; }
        }
        
        while (a!=b) {            
            a=a->next;
            b=b->next;
        }
        return a;
    }
};

2.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b=headB;
        
        // a and b will both NULL if there is no intersection
        while (a!=b) {
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        return a;
    }
};

