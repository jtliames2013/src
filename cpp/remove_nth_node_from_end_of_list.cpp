19. Remove Nth Node From End of List  QuestionEditorial Solution  My Submissions
Total Accepted: 134596 Total Submissions: 429793 Difficulty: Easy
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Subscribe to see which companies asked this question

Hide Tags Linked List Two Pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	ListNode *prev, *curr, *end;

    	if (head == NULL) return NULL;
    	if (n == 0) return head;

    	end = head;
    	while (n > 0 && end != NULL)
    	{
    		end = end->next;
    		n--;
    	}

    	if (n > 0) return head;

    	curr = head; prev = NULL;
    	while (end != NULL)
    	{
    		end = end->next;
    		prev = curr;
    		curr = curr->next;
    	}

    	if (prev == NULL) return curr->next;
    	else
    	{
    		prev->next = curr->next;
    		return head;
    	}
    }
};

2.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *one=head, *two=head, *prev=NULL;
        if (head==NULL) return NULL;
        ListNode *newHead=NULL;
        while (two!=NULL && n>0) {
            two=two->next;
            n--;
        }
        
        while (two!=NULL) {
            prev=one;
            one=one->next;
            two=two->next;
        }
        
        if (prev==NULL) {
            newHead=one->next;
        } else {
            prev->next=one->next;
            newHead=head;
        }
        delete one;
        
        return newHead;
    }
};

int main()
{
	return 0;
}

