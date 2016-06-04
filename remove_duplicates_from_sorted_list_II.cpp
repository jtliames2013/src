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
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode* curr=head;
    	ListNode* prev=NULL;
    	ListNode* next;
    	ListNode* newhead=NULL;
    	ListNode* temp;
    	bool isDup;

    	while(curr!=NULL) {
    		temp=NULL;
    		next=curr->next;
    		isDup=false;
    		while (next!=NULL && next->val==curr->val) {
				isDup=true;
				temp=curr;

				if (prev!=NULL) {
					prev->next=next;
				}

    			curr=curr->next;
    			next=curr->next;
    			delete temp;
    		}

    		if (isDup) {
    			if (prev!=NULL) {
    				prev->next=next;
    			}
    			temp=curr;
    		} else {
    			if (newhead==NULL) {
    				newhead=curr;
    			}

    			prev=curr;
    		}

    		curr=curr->next;
    		if (temp) delete temp;
    	}

    	return newhead;
    }
};

int main()
{
	return 0;
}


