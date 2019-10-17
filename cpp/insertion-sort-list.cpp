147. Insertion Sort List Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 96881
Total Submissions: 298768
Difficulty: Medium
Contributor: LeetCode
Sort a linked list using insertion sort.

Subscribe to see which companies asked this question.

Hide Tags Linked List Sort
Hide Similar Problems (M) Sort List

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        while (head) {
            ListNode *n=head;
            head=head->next;
            ListNode *prev=&dummy, *curr=dummy.next;
            while (curr && curr->val<n->val) {
                prev=curr;
                curr=curr->next;
            }
            prev->next=n;
            n->next=curr;
        }
        
        return dummy.next;
    }
};

