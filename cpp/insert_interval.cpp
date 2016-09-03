57. Insert Interval 
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Hide Company Tags LinkedIn Google Facebook
Hide Tags Array Sort
Hide Similar Problems (H) Merge Intervals

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

2. Keep the updating newInterval and insert at the end

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int pos=0;
        for (auto i:intervals) {
            if (newInterval.start>i.end) {
                res.push_back(i);
                pos++;
            } else if (newInterval.end<i.start) {
                res.push_back(i);
            } else {
                newInterval.start=min(newInterval.start, i.start);
                newInterval.end=max(newInterval.end, i.end);
            }
        }
        res.insert(res.begin()+pos, newInterval);
        
        return res;
    }
};


int main()
{
	return 0;
}

