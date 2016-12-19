109. Convert Sorted List to Binary Search Tree  QuestionEditorial Solution  My Submissions
Total Accepted: 76583 Total Submissions: 244580 Difficulty: Medium
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Hide Company Tags Zenefits
Hide Tags Depth-first Search Linked List
Hide Similar Problems (M) Convert Sorted Array to Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    	if (head == NULL) return NULL;

    	ListNode *first=head, *second=head->next, *prev=NULL;
    	while (second!=NULL)
    	{
    		prev = first;
    		first = first->next;
    		second = second->next;
    		if(second!=NULL) second=second->next;
    	}

    	TreeNode *res = new TreeNode(first->val);
    	ListNode *before;
    	ListNode *after = first->next;

    	first->next=NULL;
    	if (prev!=NULL) { prev->next=NULL; before = head; }
    	else { before = NULL; }
    	res->left = sortedListToBST(before);
    	res->right = sortedListToBST(after);

    	return res;
    }
};

2.
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode *one=head, *two=head, *prev=NULL, *next;
        while (two && two->next) {
            prev=one;
            one=one->next;
            two=two->next->next;
        }
        
        TreeNode *n=new TreeNode(one->val);
        if (prev) prev->next=NULL;
        next=one->next;
        one->next=NULL;
        n->left=sortedListToBST(head!=one?head:NULL);
        n->right=sortedListToBST(next);
        return n;
    }
};

int main()
{
	return 0;
}

