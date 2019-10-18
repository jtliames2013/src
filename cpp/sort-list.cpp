148. Sort List Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 99757
Total Submissions: 356496
Difficulty: Medium
Contributor: LeetCode
Sort a linked list in O(n log n) time using constant space complexity.

Subscribe to see which companies asked this question.

Hide Tags Linked List Sort
Hide Similar Problems (E) Merge Two Sorted Lists (M) Sort Colors (M) Insertion Sort List

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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
private:
    ListNode* mergeSort(ListNode* head) {
        if (head==NULL) return head;
        if (head->next==NULL) return head;
        ListNode *one=head, *two=head, *prev=NULL;
        while (two && two->next) {
            prev=one;
            one=one->next;
            two=two->next->next;
        }
        prev->next=NULL; //prev can't be NULL

        ListNode* l1=mergeSort(head);
        ListNode* l2=mergeSort(one);
        ListNode dummy(0);
        ListNode *tail=&dummy;
        while (l1 && l2) {
            ListNode* l;
            if (l1->val<l2->val) {
                l=l1;
                l1=l1->next;
            } else {
                l=l2;
                l2=l2->next;
            }
            tail->next=l;
            tail=l;
        }
        tail->next=l1?l1:l2;
        
        return dummy.next;
    }
};

