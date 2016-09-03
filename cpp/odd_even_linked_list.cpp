328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ... 

Note the case where even could be NULL!

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

  // Definition for a point.
  struct Point {
       int x;
       int y;
       Point() : x(0), y(0) {}
       Point(int a, int b) : x(a), y(b) {}
  };

  class Solution {
  public:
      ListNode* oddEvenList(ListNode* head) {
    	  if (head==NULL) return head;

    	  ListNode *odd=head, *even=head->next, *prev=NULL;
    	  ListNode *evenHead=even;
    	  ListNode *oddNext, *evenNext;

    	  while (odd!=NULL) {
    		  oddNext = (even ? even->next : NULL);
    		  evenNext = (oddNext ? oddNext->next : NULL);
    		  odd->next = oddNext;
    		  if (even) even->next = evenNext;

    		  prev = odd;
    		  odd = oddNext;
    		  if (even) even = evenNext;
    	  }

    	  if (prev!=NULL) prev->next=evenHead;

    	  return head;
      }
  };

2.

class Solution {

public:

    ListNode* oddEvenList(ListNode* head) {

        ListNode *oddhead=NULL, *oddtail=NULL, *evenhead=NULL, *eventail=NULL;

        ListNode *one=head, *two=head;

        

        while (one!=NULL) {

            if (oddhead==NULL) {

                oddhead=oddtail=one;

            } else {

                oddtail->next=one;

                oddtail=one;

            }

            two=one->next;

            

            if (two!=NULL) {

                if (evenhead==NULL) {

                    evenhead=eventail=two;

                } else {

                    eventail->next=two;

                    eventail=two;

                }

                

                one=two->next;

            } else {

                one=NULL;

            }

        }

        

        if (oddtail!=NULL) {

            oddtail->next=evenhead;

            if (eventail!=NULL) eventail->next=NULL;

            return oddhead;

        } else {

            return evenhead;

        }

    }

};

int main()
{
	return 0;
}

