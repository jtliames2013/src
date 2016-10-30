#include <stdio.h>
#include <stdlib.h>
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	ListNode *head = NULL, *curr = NULL;
    	if (l1 == NULL && l2 == NULL) return NULL;
    	else if (l1 == NULL) return l2;
    	else if (l2 == NULL) return l1;

    	while (l1 != NULL || l2 != NULL)
    	{
    		if (l1 != NULL && l2 != NULL)
    		{
				if (l1->val <= l2->val)
				{
					if (head == NULL)
					{
						head = l1;
						curr = l1;
					}
					else
					{
						curr->next = l1;
						curr = curr->next;
					}

					l1 = l1->next;
				}
				else
				{
					if (head == NULL)
					{
						head = l2;
						curr = l2;
					}
					else
					{
						curr->next = l2;
						curr = curr->next;
					}

					l2 = l2->next;
				}
    		}
    		else if (l1 != NULL)
    		{
    			curr->next = l1;
    			curr = curr->next;
    			l1 = l1->next;
    		}
    		else
    		{
    			curr->next = l2;
    			curr = curr->next;
    			l2 = l2->next;
    		}
    	}

    	return head;
    }
};


2. Use common code to dertermine if head is NULL

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL;
        ListNode *tail=NULL;
        ListNode *l;
        while (l1!=NULL || l2!=NULL) {
            if (l1==NULL) {
                l=l2;
                l2=l2->next;
            } else if (l2==NULL) {
                l=l1;
                l1=l1->next;
            } else {
                if (l1->val>=l2->val) {
                    l=l2;
                    l2=l2->next;
                } else {
                    l=l1;
                    l1=l1->next;
                }
            }
            
            if (head==NULL) {
                head=tail=l;
            } else {
                tail->next=l;
                tail=l;
            }
        }        
        return head;
    }
};

3. No need to iterate when there is only one list left
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL, *tail=NULL;
        ListNode *node;
        while (l1 && l2) {
            if (l1->val>l2->val) {
                node=l2;
                l2=l2->next;
            } else {
                node=l1;
                l1=l1->next;
            }
            if (head==NULL) {
                head=tail=node;
            } else {
                tail->next=node;
                tail=node;
            }
        }
        if (l1) node=l1;
        else node=l2;
        
        if (head==NULL) {
            head=node;
        } else {
            tail->next=node;
        }
        
        return head;
    }
};

int main()
{
	return 0;
}

