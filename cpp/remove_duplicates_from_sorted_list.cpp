83. Remove Duplicates from Sorted List  QuestionEditorial Solution  My Submissions
Total Accepted: 132118 Total Submissions: 350806 Difficulty: Easy
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
        if (head==NULL) return NULL;
        ListNode *prev=head, *curr=head->next, *tmp;
        while (curr) {
            if (curr->val==prev->val) {
                tmp=curr;
                prev->next=curr->next;
                delete tmp;
            } else {
                prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};

2.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr=head, *tmp;
        while (curr!=NULL) {
            if (curr->next && curr->next->val==curr->val) {
                tmp=curr->next;
                curr->next=curr->next->next;
                delete tmp;
            } else {
                curr=curr->next;
            }
        }
        return head;
    }
};

int main()
{
	return 0;
}

