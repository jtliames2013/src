
#include <stdio.h>
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
    ListNode *deleteDuplicates(ListNode *head) {
    	if (head == NULL) return NULL;

    	ListNode *prev = head, *curr= head->next, *temp;

    	while (curr)
    	{
    		if (curr->val == prev->val)
    		{
    			temp = curr;
    			prev->next = curr->next;
    			curr = curr->next;
    			delete temp;
    		}
    		else
    		{
    			prev = curr;
    			curr = curr->next;
    		}
    	}

    	return head;
    }
};

int main()
{
	return 0;
}

