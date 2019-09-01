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
        int i, n=intervals.size();
        for (i=0; i<n; i++) {
            if (intervals[i].end<newInterval.start) {
                res.push_back(intervals[i]);
            } else if (intervals[i].start>newInterval.end) {
                break;   
            } else {
                newInterval.start=min(newInterval.start, intervals[i].start);
                newInterval.end=max(newInterval.end, intervals[i].end);
            }
        }
        res.push_back(newInterval);
        for (; i<n; i++) res.push_back(intervals[i]);
        return res;
    }
};


2. vector as Interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size(), i=0;       
        for (; i<n; ++i) {
            if (intervals[i][1]<newInterval[0]) res.push_back(intervals[i]);
            else if (intervals[i][0]>newInterval[1]) break;
            else {
                newInterval[0]=min(newInterval[0], intervals[i][0]);
                newInterval[1]=max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        for (; i<n; ++i) res.push_back(intervals[i]);
                
        return res;
    }
};
