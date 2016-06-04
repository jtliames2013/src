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
    ListNode* partition(ListNode* head, int x) {
    	ListNode *less=NULL, *lessEnd=NULL;
    	ListNode *more=NULL, *moreEnd=NULL;
    	ListNode *curr=head;
    	ListNode *res=NULL;

    	while (curr!=NULL) {
    		if (curr->val<x) {
    			if (lessEnd==NULL) {
    				less=lessEnd=curr;
    			} else {
    				lessEnd->next=curr;
    				lessEnd=curr;
    			}
    		} else if (curr->val>=x) {
    			if (moreEnd==NULL) {
    				more=moreEnd=curr;
    			} else {
    				moreEnd->next=curr;
    				moreEnd=curr;
    			}

    		}

    		curr=curr->next;
    	}

    	if (lessEnd!=NULL) lessEnd->next=NULL;
    	if (moreEnd!=NULL) moreEnd->next=NULL;

    	if (less!=NULL) {
    		res=less;
    		lessEnd->next=more;
    	} else{
    		res=more;
    	}

    	return res;
    }
};

int main()
{
	return 0;
}


