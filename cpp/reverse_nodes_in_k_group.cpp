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

int main()
{
	return 0;
}

