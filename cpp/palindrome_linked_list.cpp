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
      bool isPalindrome(ListNode* head) {
    	  ListNode *one=head, *two=head;
    	  ListNode *prev=NULL;
    	  while (two!=NULL && two->next!=NULL) {
    		  one=one->next;
    		  two=two->next->next;
    	  }

    	  // reverse from one
    	  while (one!=NULL) {
    		  ListNode *next=one->next;
    		  one->next=prev;
    		  prev=one;
    		  one=next;
    	  }

    	  ListNode *front=head, *back=prev;
    	  while (back!=NULL) {
    		  if (back->val!=front->val) return false;
    		  front=front->next;
    		  back=back->next;
    	  }
    	  return true;
      }
  };

int main()
{
	return 0;
}

