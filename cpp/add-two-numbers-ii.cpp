445. Add Two Numbers II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 19024
Total Submissions: 41221
Difficulty: Medium
Contributor: LeetCode
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
Subscribe to see which companies asked this question.

Hide Tags Linked List
Hide Similar Problems (M) Add Two Numbers

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
        stack<int> stk1, stk2;
        while (l1) {
            stk1.push(l1->val);
            l1=l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2=l2->next;
        }
        ListNode* head=NULL;
        int num=0;
        while (!stk1.empty()||!stk2.empty()) {
            if (!stk1.empty()) { num+=stk1.top(); stk1.pop(); }
            if (!stk2.empty()) { num+=stk2.top(); stk2.pop(); }
            ListNode* n=new ListNode(num%10);
            num/=10;
            n->next=head;
            head=n;
        }
        if (num!=0) {
            ListNode* n=new ListNode(num);
            n->next=head;
            head=n;
        }
        return head;
    }
};
