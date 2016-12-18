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
    bool hasCycle(ListNode *head) {
    	if (head == NULL) return false;

    	ListNode *first = head, *second = head;

    	while (second != NULL)
    	{
    		first = first->next;
    		second = second->next;
    		if (second != NULL) second = second->next;

    		if (first == second) break;
    	}

    	if (second == NULL) return false;
    	else return true;
    }
};

2.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *one=head, *two=head;
        while (1) {
            if (two!=NULL && two->next!=NULL) two=two->next->next;
            else return false;
            one=one->next;
            if (one==two) return true;
        }
    }
};

int main()
{
	return 0;
}

