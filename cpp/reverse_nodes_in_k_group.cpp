25. Reverse Nodes in k-Group   QuestionEditorial Solution  My Submissions
Total Accepted: 72858 Total Submissions: 250322 Difficulty: Hard Contributors: Admin
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Subscribe to see which companies asked this question

Hide Tags Linked List
Hide Similar Problems (E) Swap Nodes in Pairs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

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

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	ListNode *start=head, *end=head, *prev=NULL;
    	ListNode *newHead=head;
    	ListNode *newEnd=NULL;
    	int cnt;
    	if (k<=1) return head;

    	while (1) {
    		cnt=k-1;

    		while (end!=NULL && cnt>0) {
    			end=end->next;
    			cnt--;
    		}
    		if (end==NULL) {
    			if (newEnd!=NULL) newEnd->next=start;
    			return newHead;
    		}

    		if (newEnd!=NULL) newEnd->next=end;
    		if (newHead==head) newHead=end;
    		newEnd=start;

    		ListNode *endNext=end->next;
    		ListNode *curr=start;
    		while (curr!=endNext) {
    			ListNode *next = curr->next;
    			curr->next=prev;
    			prev=curr;
    			curr=next;
    		}

    		start=end=endNext;
    	}
    }
};

2.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL) return NULL;
        if (k<=1) return head;
        ListNode *prevEnd=NULL, *start=head, *end=NULL, *nextStart=head;
        ListNode *newHead=head;
        
        while (1) {
            int count=k;
            while (count>0 && nextStart!=NULL) {
                end=nextStart;
                nextStart=nextStart->next;
                count--;
            }
            if (count>0) break;
            
            // prevEnd->start->...->end->nexStart
            // from start, keep insert at the next of end
            ListNode *curr=start, *next;
            while (curr!=end) {
                next=curr->next;
                curr->next=end->next;
                end->next=curr;
                curr=next;
            }
            if (prevEnd==NULL) {
                newHead=curr;
            } else {
                prevEnd->next=curr;
            }
            
            prevEnd=start;
            start=nextStart;
        }
        return newHead;
    }
};

int main()
{
	return 0;
}

