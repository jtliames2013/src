364. Nested List Weight Sum II 
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)

Hide Company Tags LinkedIn
Hide Tags Depth-first Search
Hide Similar Problems (E) Nested List Weight Sum

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
   /**/
  class Solution {
  public:
	  int getDepth(const vector<NestedInteger>& nestedList) {
		  int depth=0;
		  for (int i=0; i<nestedList.size(); i++) {
			  if (nestedList[i].isInteger()) depth=max(depth, 1);
			  else {
				  depth=max(depth, getDepth(nestedList[i].getList())+1);
			  }
		  }
		  return depth;
	  }

	  void getSum(const vector<NestedInteger>& nestedList, int& sum, int depth) {
		  for (int i=0; i<nestedList.size(); i++) {
			  if (nestedList[i].isInteger()) {
				  sum+=nestedList[i].getInteger()*depth;
			  } else {
				  getSum(nestedList[i].getList(), sum, depth-1);
			  }
		  }
	  }
      int depthSumInverse(vector<NestedInteger>& nestedList) {
    	  int depth=getDepth(nestedList);
    	  int sum=0;
    	  getSum(nestedList, sum, depth);

    	  return sum;
      }
  };

int main()
{
	return 0;
}

