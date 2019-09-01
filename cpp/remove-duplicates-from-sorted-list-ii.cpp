82. Remove Duplicates from Sorted List II  QuestionEditorial Solution  My Submissions
Total Accepted: 80840 Total Submissions: 291915 Difficulty: Medium
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode *prev=&dummy, *curr=head, *next=NULL;
        while (curr) {
            next=curr->next;
            bool del=next&&next->val==curr->val;
            while (next&&next->val==curr->val) {
                next=next->next;
            }
            
            if (del) {
                prev->next=next;
            } else {
                prev=curr;
            }
            curr=next;
        }
        
        return dummy.next;
    }
};

