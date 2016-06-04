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

  class Queue {
  public:
      stack<int> in;
      stack<int> out;

      // Push element x to the back of queue.
      void push(int x) {
    	  in.push(x);
      }

      // Removes the element from in front of queue.
      void pop(void) {
    	  if (out.empty()) {
    		  while (!in.empty()) {
    			  out.push(in.top());
    			  in.pop();
    		  }
    	  }

    	  if (!out.empty()) out.pop();
      }

      // Get the front element.
      int peek(void) {
    	  if (in.empty() && out.empty()) return 0;
    	  else if (out.empty()) {
    		  while (!in.empty()) {
    			  out.push(in.top());
    			  in.pop();
    		  }
    	  }

    	  return out.top();
      }

      // Return whether the queue is empty.
      bool empty(void) {
          return (in.empty() && out.empty());
      }
  };

int main()
{
	return 0;
}

