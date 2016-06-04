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
    ListNode *detectCycle(ListNode *head) {
    	if (head == NULL) return NULL;

    	ListNode *first = head, *second = head;
    	while (second != NULL)
    	{
    		first = first->next;
    		second = second->next;
    		if (second != NULL) second = second->next;

    		if (first == second) break;
    	}

    	if (second == NULL) return NULL;

    	ListNode *l1 = head, *l2 = first;
    	while (l1 != l2)
    	{
    		l1 = l1->next;
    		l2 = l2->next;
    	}

    	return l1;
    }
};

int main()
{
	return 0;
}

