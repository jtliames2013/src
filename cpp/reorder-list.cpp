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
        if (head==NULL || head->next==NULL) return;
        ListNode *one=head, *two=head, *curr, *prev=NULL, *next;
        while (two && two->next) {
            one=one->next;
            two=two->next->next;
        }
        
        // reverse the second half
        curr=one->next;
        one->next=NULL;
        while (curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        ListNode dummy(0);
        ListNode *l1=head, *l2=prev, *tail=&dummy;        
        while (l2) {
            tail->next=l1;
            tail=l1;
            l1=l1->next;            
            tail->next=l2;
            tail=l2;
            l2=l2->next;            
        }
        tail->next=l1;
        dummy.next=NULL;
    }
};
