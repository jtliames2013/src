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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	vector<Interval> res;
    	int size=intervals.size();
    	bool inserted=false;
    	bool findingEnd=false;
    	bool started=false;
    	int start;
    	if (size==0) {
    		res.push_back(newInterval);
    		return res;
    	}

    	for (int i=0; i<size; i++) {
    		if (inserted) {
    			res.push_back(intervals[i]);
    		} else if (findingEnd) {
    			// newInterval.start must be less than intervals[i].start
    			if (newInterval.end < intervals[i].start) {
    				Interval in(start, newInterval.end);
    				res.push_back(in);
    				res.push_back(intervals[i]);
    				findingEnd=false;
    				inserted=true;
    			} else if (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end) {
    				Interval in(start, intervals[i].end);
    				res.push_back(in);
    				findingEnd=false;
    				inserted=true;
    			}
    		} else {
				if (intervals[i].end < newInterval.start) {
					res.push_back((intervals[i]));
				} else if (intervals[i].start > newInterval.start) {
					if (newInterval.end < intervals[i].start) {
						res.push_back(newInterval);
						res.push_back(intervals[i]);
						inserted=true;
					} else if (newInterval.end > intervals[i].end) {
						start=newInterval.start;
						findingEnd=true;
					} else {
						Interval in(newInterval.start, intervals[i].end);
						res.push_back((in));
						inserted=true;
					}
					started=true;
				} else {
					start = intervals[i].start;
					started=true;
					if (newInterval.end <= intervals[i].end) {
						Interval in(start, intervals[i].end);
						res.push_back(in);
						inserted=true;
					} else {
						findingEnd=true;
					}
				}
    		}
    	}

    	if (findingEnd==true) {
    		Interval in(start, newInterval.end);
    		res.push_back(in);
    	} else if (!started) {
    		res.push_back(newInterval);
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

