234. Palindrome Linked List Add to List
DescriptionSubmissionsSolutions
Total Accepted: 95231
Total Submissions: 296692
Difficulty: Easy
Contributor: LeetCode
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

Subscribe to see which companies asked this question.

Hide Tags Linked List Two Pointers
Hide Similar Problems (E) Palindrome Number (E) Valid Palindrome (E) Reverse Linked List

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
    bool isPalindrome(ListNode* head) {
        ListNode *one=head, *two=head, *prev=NULL, *next;
        while (two && two->next) {
            one=one->next;
            two=two->next->next;
        }
        
        // reverse list from one
        while (one) {
            next=one->next;
            one->next=prev;
            prev=one;
            one=next;
        }
        
        ListNode *front=head, *back=prev;
        while (back) {
            if (back->val!=front->val) return false;
            front=front->next;
            back=back->next;
        }
        return true;
    }
};

