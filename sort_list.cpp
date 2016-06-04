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
	ListNode* mergeSort(ListNode *head)
	{
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;

		ListNode *prev = NULL, *first = head, *second = head;

		while (second != NULL)
		{
			prev = first;
			first = first->next;
			second = second->next;
			if (second != NULL) second = second->next;
		}
		prev->next = NULL;

		ListNode *l1 = mergeSort(head);
		ListNode *l2 = mergeSort(first);

		ListNode *res = NULL;
		ListNode *curr = NULL;
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL || (l2 != NULL && l2->val < l1->val))
			{
				if (curr == NULL)
				{
					curr = l2;
					res = curr;
				}
				else
				{
					curr->next = l2;
					curr = curr->next;
				}
				l2 = l2->next;
			}
			else
			{
				if (curr == NULL)
				{
					curr = l1;
					res = curr;
				}
				else
				{
					curr->next = l1;
					curr = curr->next;
				}
				l1 = l1->next;
			}
		}

		return res;
	}

    ListNode *sortList(ListNode *head) {
    	return mergeSort(head);
    }
};

int main()
{
	return 0;
}

