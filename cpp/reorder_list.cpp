143. Reorder List Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 88303
Total Submissions: 352480
Difficulty: Medium
Contributor: LeetCode
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

Subscribe to see which companies asked this question.

Hide Tags Linked List

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
    void reorderList(ListNode* head) {
        if (head==NULL||head->next==NULL) return;
        ListNode *one=head, *two=head, *prev=NULL;
        while (two) {
            two=two->next?two->next->next:NULL;
            prev=one;
            one=one->next;
        }
        prev->next=NULL;
        
        // reverse second half
        prev=NULL;
        ListNode *next;
        while (one) {
            next=one->next;
            one->next=prev;
            prev=one;
            one=next;
        }
        
        ListNode *l1=head, *l2=prev, *l1next, *l2next;
        while (l2) {
            l1next=l1->next;
            l2next=l2->next;
            l1->next=l2;
            l2->next=l1next;
            l1=l1next;
            l2=l2next;
        }
    }
};

