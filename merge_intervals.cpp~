56. Merge Intervals 
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Hide Company Tags LinkedIn Google Facebook Twitter Microsoft Bloomberg Yelp
Hide Tags Array Sort
Hide Similar Problems (H) Insert Interval (E) Meeting Rooms (M) Meeting Rooms II

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

2.
这道和之前那道 Insert Interval 插入区间 很类似，这次题目要求我们合并区间，之前那题明确了输入区间集是有序的，而这题没有，所有我们首先要做的就是给区间集排序，由于我们要排序的是个结构体，所以我们要定义自己的comparator，才能用sort来排序，我们以start的值从小到大来排序，排完序我们就可以开始合并了，首先把第一个区间存入结果中，然后从第二个开始遍历区间集，如果结果中最后一个区间和遍历的当前区间无重叠，直接将当前区间存入结果中，如果有重叠，将结果中最后一个区间的end值更新为结果中最后一个区间的end和当前end值之中的较大值，然后继续遍历区间集，以此类推可以得到最终结果，代码如下：

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int size=intervals.size();
        if (size==0) return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start<b.start;});
        
        res.push_back(intervals[0]);
        for (int i=1; i<size; i++) {
            if (res.back().end<intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.back().end=max(res.back().end, intervals[i].end);
            }
        }
        
        return res;
    }
};

int main()
{
	return 0;
}

