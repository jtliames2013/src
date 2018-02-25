21. Merge Two Sorted Lists Add to List
DescriptionSubmissionsSolutions
Total Accepted: 207116
Total Submissions: 538019
Difficulty: Easy
Contributor: LeetCode
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Subscribe to see which companies asked this question.

Hide Tags Linked List
Hide Similar Problems (H) Merge k Sorted Lists (E) Merge Sorted Array (M) Sort List (M) Shortest Word Distance II

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail=&dummy;
        while (l1 && l2) {
            if (l1->val<l2->val) {
                tail->next=l1;
                l1=l1->next;
            } else {
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }

        tail->next=l1?l1:l2;

        return dummy.next;
    }
};

