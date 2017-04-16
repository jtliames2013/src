92. Reverse Linked List II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 103483
Total Submissions: 343460
Difficulty: Medium
Contributor: LeetCode
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

Subscribe to see which companies asked this question.

Hide Tags Linked List
Hide Similar Problems (E) Reverse Linked List

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n) return head;
        ListNode *prev=NULL, *curr=head, *next, *newHead=head;
        int i=0;
        while (curr) {
            i++;
            if (i==m) break;
            prev=curr;
            curr=curr->next;
        }
        
        ListNode *tail=prev, *start=curr;
        while (curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
            if (i>n) break;
        }
        
        if (tail==NULL) {
            newHead=prev;
        } else {
            tail->next=prev;
        }
        start->next=next;
        
        return newHead;
    }
};

