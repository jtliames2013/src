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
     vector<Interval> merge(vector<Interval>& intervals) {
    	 vector<Interval> res;
    	 int start, end;
    	 bool isOpen=false;

    	 struct {
    	         bool operator()(Interval a, Interval b)
    	         {
    	             return a.start < b.start;
    	         }
    	 } customLess;
    	 std::sort(intervals.begin(), intervals.end(), customLess);

    	 for (int i=0; i<intervals.size(); i++) {
    		 if (isOpen==false) {
    			 start=intervals[i].start;
    			 end=intervals[i].end;
    			 isOpen=true;
    		 } else {
    			 if (end < intervals[i].start) {
    				 res.push_back(Interval(start, end));
    				 start=intervals[i].start;
    				 end=intervals[i].end;
    			 } else if (end >= intervals[i].start && end <= intervals[i].end) {
    				 end=intervals[i].end;
    			 }
    		 }
    	 }

    	 if (isOpen) {
    		 res.push_back(Interval(start, end));
    	 }

    	 return res;
     }
 };

int main()
{
	return 0;
}

