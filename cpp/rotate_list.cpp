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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (head==NULL) return NULL;

    	int size=0;
    	ListNode* curr=head;
    	ListNode* tail=NULL;
    	while (curr!=NULL) {
    		size++;
    		tail=curr;
    		curr=curr->next;
    	}

    	k=k%size;
    	int n=size-k;
    	ListNode* prev=NULL;
    	curr=head;
		if (k>0) {
			while (n>0) {
				prev=curr;
				curr=curr->next;
				n--;
			}

			prev->next=NULL;
			tail->next=head;
    	}

    	return curr;
    }
};

int main()
{
	return 0;
}


