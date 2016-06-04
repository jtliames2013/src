Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6]. 

Note: Flatten the nested list into a vector using recursion.

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
#include <unordered_map>
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

  /**
   * // This is the interface that allows for creating nested lists.
   * // You should not implement it, or speculate about its implementation */
    class NestedInteger {
      public:
        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger> &getList() const;
    };

  class NestedIterator {
  public:
	  vector<int> flatList;
	  int index;

	  void getFlatList(vector<int> &flatList, const vector<NestedInteger> &nestedList) {
		  for (auto n:nestedList) {
			  if (n.isInteger()) {
				  flatList.push_back(n.getInteger());
			  } else {
				  getFlatList(flatList, n.getList());
			  }
		  }
	  }

      NestedIterator(vector<NestedInteger> &nestedList) {
    	  getFlatList(flatList, nestedList);
    	  index=0;
      }

      int next() {
    	  int res=flatList[index];
    	  index++;
    	  return res;
      }

      bool hasNext() {
    	  return (index<flatList.size());
      }
  };

  /**
   * Your NestedIterator object will be instantiated and called as such:
   * NestedIterator i(nestedList);
   * while (i.hasNext()) cout << i.next();
   */

int main()
{
	return 0;
}


