#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

  class Solution {
  public:
      ListNode* removeElements(ListNode* head, int val) {
    	  ListNode *prev=NULL, *curr=head;
    	  ListNode *newHead=head;

    	  while (curr!=NULL) {
    		  if (curr->val==val) {
    			  ListNode *tmp=curr;
    			  curr=curr->next;
    			  if (prev==NULL) {
    				  newHead=curr;
    			  } else {
    				  prev->next=curr;
    			  }
    			  delete tmp;
    		  } else {
    			  prev=curr;
    			  curr=curr->next;
    		  }
    	  }

    	  return newHead;
      }
  };

2.
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL) return NULL;
        ListNode *prev=NULL, *curr=head, *next=NULL, *newHead=NULL;
        while (curr!=NULL) {
            next=curr->next;
            if (curr->val==val) {
                if (prev!=NULL) prev->next=next;
                delete curr;
            } else {
                if (newHead==NULL) newHead=curr;
                prev=curr;
            }
            curr=next;
        }
        
        return newHead;
    }
};

3. Use dummy node
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy, *curr=head;
        while (curr!=NULL) {
            if (curr->val==val) {
                prev->next=curr->next;
            } else {
                prev=curr;
            }
            curr=curr->next;
        }
        
        ListNode *newHead=dummy->next;
        delete dummy;
        return newHead;
    }
};

int main()
{
	return 0;
}

