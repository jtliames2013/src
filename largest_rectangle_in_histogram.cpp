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

 class Solution {
 public:
     int largestRectangleArea(vector<int>& heights) {
    	 int size=heights.size();
    	 if (size==0) return 0;
    	 stack<int> stk;
    	 int maxArea=0;

    	 for (int i=0; i<heights.size(); i++) {
    		 while (!stk.empty() && heights[stk.top()]>heights[i]) {
    			 int h=heights[stk.top()];
    			 stk.pop();
    			 if (stk.empty()) {
    				 maxArea=max(maxArea, i * h);
    			 } else {
    				 maxArea=max(maxArea, (i-stk.top()-1)*h);
    			 }
    		 }

    		 stk.push(i);
    	 }

    	 while (!stk.empty()) {
			 int h=heights[stk.top()];
			 stk.pop();
			 if (stk.empty()) {
				 maxArea=max(maxArea, size * h);
			 } else {
				 maxArea=max(maxArea, (size-stk.top()-1)*h);
			 }
		 }

    	 return maxArea;
     }
 };

int main()
{
	return 0;
}

