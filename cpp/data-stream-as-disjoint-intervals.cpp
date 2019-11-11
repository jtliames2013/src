352. Data Stream as Disjoint Intervals 
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

Credits:
Special thanks to @yunhong for adding this problem and creating most of the test cases.

Hide Tags Binary Search Tree
Hide Similar Problems (M) Summary Ranges

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        int pos=0;
        Interval curr(val, val);
        auto iter=intervals.begin();
        for (; iter<intervals.end(); ) {
            if (iter->end+1<curr.start) iter++;
            else if (iter->start-1>curr.end) {
                break;
            } else {
                curr.start=min(curr.start, iter->start);
                curr.end=max(curr.end, iter->end);
                iter=intervals.erase(iter);
            }
        }
        intervals.insert(iter, curr);
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
private:
    vector<Interval> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

2. Binary search
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval curr(val,val);
        auto comp=[](Interval a, Interval b) { return a.start<b.start; };
        auto iter=lower_bound(intervals.begin(), intervals.end(), curr, comp);
        if (iter!=intervals.begin()) iter--;
        if (iter!=intervals.end() && iter->end+1<curr.start) iter++;
        for (; iter!=intervals.end() && iter->end>=curr.start-1 && iter->start<=curr.end+1; ) {
            curr.start=min(curr.start, iter->start);
            curr.end=max(curr.end, iter->end);
            iter=intervals.erase(iter);
        }
        intervals.insert(iter, curr);
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
private:
    vector<Interval> intervals;
};

