56. Merge Intervals 
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Hide Company Tags LinkedIn Google Facebook Twitter Microsoft Bloomberg Yelp
Hide Tags Array Sort
Hide Similar Problems (H) Insert Interval (E) Meeting Rooms (M) Meeting Rooms II

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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int n=intervals.size();
        if (n==0) return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        
        res.push_back(intervals[0]);
        for (int i=1; i<n; i++) {
            if (intervals[i].start>res.back().end) res.push_back(intervals[i]);
            else {
                res.back().end=max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};

