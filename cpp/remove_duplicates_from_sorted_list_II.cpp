82. Remove Duplicates from Sorted List II  QuestionEditorial Solution  My Submissions
Total Accepted: 80840 Total Submissions: 291915 Difficulty: Medium
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

1.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode *prev=NULL, *curr=head, *next=NULL;
        ListNode *newHead=NULL;
        while (curr!=NULL) {
            next=curr->next;
            if (next==NULL || next->val!=curr->val) {
                if (newHead==NULL) newHead=curr;
                prev=curr;
                curr=next;
            } else {
                while (next!=NULL && next->val==curr->val) next=next->next;
                if (prev!=NULL) {
                    prev->next=next;
                }
                curr=next;
            }
        }
        return newHead;
    }
};

2.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *curr=head, *prev=dummy, *tmp;
        while (curr!=NULL) {
            if (curr->next && curr->next->val==curr->val) {
                int val=curr->val;
                while (curr && curr->val==val) {
                    tmp=curr;
                    curr=curr->next;
                    delete tmp;
                }
                prev->next=curr;
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
        
        ListNode *newHead=dummy->next;
        delete dummy;
        return newHead;
    }
};

int main()
{
	return 0;
}


