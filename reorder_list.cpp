#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>

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
    void reorderList(ListNode *head) {
    	if (head == NULL) return;

    	// cut list into half
    	ListNode *first = head, *second = head, *prev = NULL;
    	while (second != NULL)
    	{
    		prev = first;
    		first = first->next;
    		second = second->next;
    		if (second != NULL) second = second->next;
    	}
    	prev->next = NULL;

    	// reverse first list
    	ListNode *curr = first, *temp;
    	prev = NULL;

    	while (curr != NULL)
    	{
    		temp = curr->next;
    		curr->next = prev;
    		prev = curr;
    		curr = temp;
    	}

    	// interleave prev list into head
    	ListNode *l1 = head, *l2 = prev, *l1next, *l2next;
    	while (l2 != NULL)
    	{
    		l2next = l2->next;
    		l1next = l1->next;
    		l1->next = l2;
    		l2->next = l1next;
    		l1 = l1next;
    		l2 = l2next;
    	}
    }
};

int main()
{
	return 0;
}

