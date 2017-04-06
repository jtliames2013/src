203. Remove Linked List Elements Add to List
DescriptionSubmissionsSolutions
Total Accepted: 105779
Total Submissions: 334748
Difficulty: Easy
Contributor: LeetCode
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Linked List
Hide Similar Problems (E) Remove Element (E) Delete Node in a Linked List

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode *curr=head, *prev=&dummy;
        while (curr) {
            if (curr->val==val) {
                prev->next=curr->next;
            } else {
                prev=curr;
            }
            curr=curr->next;
        }
        
        return dummy.next;
    }
};

