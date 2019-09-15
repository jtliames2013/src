141. Linked List Cycle Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 170576
Total Submissions: 480483
Difficulty: Easy
Contributor: LeetCode
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Subscribe to see which companies asked this question.

Hide Tags Linked List Two Pointers
Hide Similar Problems (M) Linked List Cycle II

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
    bool hasCycle(ListNode *head) {
        ListNode *one=head, *two=head;
        while (two && two->next) {
            one=one->next;
            two=two->next->next;
            if (one==two) return true;
        }
        return false;
    }
};
