#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	if (!head) return NULL;
    	ListNode *res;

    	ListNode *start=NULL, *end=NULL, *beforeStart=NULL, *afterEnd=NULL;
    	int i=1;
    	ListNode *node=head, *prev=NULL;
    	while (node!=NULL)
    	{
    		if (i==m)
    		{
    			start=node;
    			beforeStart=prev;
    		}
    		if (i==n)
    		{
    			end=node;
    			afterEnd=end->next;
    		}
    		prev=node;
    		node=node->next;
    		i++;
    	}

    	node=start;
    	prev=NULL;
    	ListNode *tmp;
    	while (node!=afterEnd)
    	{
    		tmp=node->next;
    		node->next=prev;
    		prev=node;
    		node=tmp;
    	}

    	start->next = afterEnd;
    	if (beforeStart!=NULL)
    	{
    		beforeStart->next=end;
    		res=head;
    	}
    	else
    	{
    		res=end;
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

