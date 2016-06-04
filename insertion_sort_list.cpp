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
    ListNode *insertionSortList(ListNode *head) {
    	if (head == NULL) return NULL;

    	ListNode *curr = head;
    	ListNode *sorted = NULL;
    	ListNode *sortedPrev, *sortedCurr;
    	ListNode *temp;
    	while (curr != NULL)
    	{
    		sortedPrev = NULL;
    		sortedCurr = sorted;
    		while (sortedCurr != NULL)
    		{
    			if (sortedCurr->val > curr->val) break;
    			sortedPrev = sortedCurr;
    			sortedCurr = sortedCurr->next;
    		}

    		temp = curr->next;
    		if (sortedPrev == NULL)
    		{
    			sorted = curr;
    			curr->next = sortedCurr;
    		}
    		else
    		{
    			sortedPrev->next  = curr;
    			curr->next = sortedCurr;
    		}

    		curr = temp;
    	}

    	return sorted;
    }
};

int main()
{
	return 0;
}

