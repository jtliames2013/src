206. Reverse Linked List Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 210962
Total Submissions: 473751
Difficulty: Easy
Contributor: LeetCode
Reverse a singly linked list.

click to show more hints.

Subscribe to see which companies asked this question.

Hide Tags Linked List
Hide Similar Problems (M) Reverse Linked List II (M) Binary Tree Upside Down (E) Palindrome Linked List

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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL, *curr=head, *next;
        while (curr!=NULL) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
