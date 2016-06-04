nclude <stdio.h>
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

int main()
{
	return 0;
}

