#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };


 // Definition for singly-linked list with a random pointer.
  struct RandomListNode {
       int label;
       RandomListNode *next, *random;
       RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

1. Use mapping between node 

class Solution {

public:

    RandomListNode *copyRandomList(RandomListNode *head) {

        unordered_map<RandomListNode*, RandomListNode*> copyToOrig;

        unordered_map<RandomListNode*, RandomListNode*> origToCopy;

        

        RandomListNode *curr=head;

        RandomListNode *newhead=NULL, *prev=NULL;

        while (curr!=NULL) {

            RandomListNode *n=new RandomListNode(curr->label);

            if (newhead==NULL) newhead=n;

            if (prev!=NULL) prev->next=n;

            prev=n;

            copyToOrig[n]=curr;

            origToCopy[curr]=n;

            curr=curr->next;

        }

        

        curr=newhead;

        while (curr!=NULL) {

            curr->random=copyToOrig[curr]->random==NULL?NULL:origToCopy[copyToOrig[curr]->random];

            curr=curr->next;

        }

        

        return newhead;

    }

};

2. Use no extra space

 class Solution {
 public:
     RandomListNode *copyRandomList(RandomListNode *head) {
    	 if (head==NULL) return NULL;
    	 RandomListNode *curr=head;

    	 // duplicate node
    	 while (curr!=NULL) {
    		 RandomListNode *n=new RandomListNode(curr->label);
    		 RandomListNode *next=curr->next;
    		 curr->next=n;
    		 n->next=next;
    		 curr=next;
    	 }

    	 // duplicate random pointer
    	 curr=head;
    	 while (curr!=NULL) {
    		 curr->next->random = curr->random!=NULL ? curr->random->next : NULL;
    		 curr=curr->next->next;
    	 }

    	 // separate the list
    	 curr=head;
    	 RandomListNode* newHead=curr->next;
    	 while (curr!=NULL) {
    		 RandomListNode* nextnext = curr->next->next;
    		 RandomListNode* next=curr->next;

    		 curr->next=nextnext;
    		 next->next=nextnext!=NULL ? nextnext->next : NULL;
    		 curr=nextnext;
    	 }

    	 return newHead;
     }
 };

int main()
{
	return 0;
}

