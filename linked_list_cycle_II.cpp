142. Linked List Cycle II 
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

如果有环，如何判断环的起始点。
假设linked list从head到环起始点s的长度为L，环的周长为C（两节点之间的长度为之间link的数量）
当fast与slow第一次相遇的位置记为m1，并假设m1离开环起始点s距离X，由于fast走的总路程一定是slow的两倍：
(L + j*C + X)*2 = L + i*C + X => L = n*C - X
从m1出发，走n*C - X的路程将回到s，而这段路程正好等于head到s之间的路程！所以第一次相遇后，将slow移到head，然后slow/fast同时以一次走一步的速度前进，直到它们第二次相遇，便是s了。

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

2.

class Solution {

public:

    ListNode *detectCycle(ListNode *head) {

        ListNode *one=head, *two=head;

        

        while (1) {

            if (one!=NULL) one=one->next;

            if (two!=NULL && two->next!=NULL) two=two->next->next;

            else return NULL;

            

            if (one==two) break;

        }

        

        one=head;

        while (one!=two) {

            one=one->next;

            two=two->next;

        }

        

        return one;

    }

};

int main()
{
	return 0;
}

