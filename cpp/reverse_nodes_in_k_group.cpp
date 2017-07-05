25. Reverse Nodes in k-Group   QuestionEditorial Solution  My Submissions
Total Accepted: 72858 Total Submissions: 250322 Difficulty: Hard Contributors: Admin
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Subscribe to see which companies asked this question

Hide Tags Linked List
Hide Similar Problems (E) Swap Nodes in Pairs

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL) return NULL;
        if (k<=1) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode *prevEnd=&dummy, *start=head, *end=NULL, *nextStart=head;                
        
        while (1) {
            int count=k;
            while (count>0 && nextStart!=NULL) {
                end=nextStart;
                nextStart=nextStart->next;
                count--;
            }
            if (count>0) break;
            
            // prevEnd->start->...->end->nexStart
            // from start, keep insert at the next of end
            ListNode *curr=start, *next;
            while (curr!=end) {
                next=curr->next;
                curr->next=end->next;
                end->next=curr;
                curr=next;
            }
            prevEnd->next=curr;
            
            prevEnd=start;
            start=nextStart;
        }
        return dummy.next;
    }
};

