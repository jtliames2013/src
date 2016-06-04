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
      ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	  int aLen=0, bLen=0;
    	  ListNode *n, *a, *b;
    	  n=headA;
    	  while (n!=NULL) {
    		  aLen++;
    		  n=n->next;
    	  }
    	  n=headB;
    	  while (n!=NULL) {
    		  bLen++;
    		  n=n->next;
    	  }

    	  a=headA;
    	  b=headB;
    	  if (aLen>bLen) {
    		  while (aLen>bLen) {
    			  aLen--;
    			  a=a->next;
    		  }
    	  } else if (aLen<bLen) {
    		  while (bLen>aLen) {
    			  bLen--;
    			  b=b->next;
    		  }
    	  }

    	  while (a!=NULL) {
    		  if (a==b) return a;
    		  a=a->next;
    		  b=b->next;
    	  }

    	  return NULL;
      }
  };

int main()
{
	return 0;
}

