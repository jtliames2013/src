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
        vector<Interval> res;
        Interval curr(val, val);
        int pos=0;
        for (auto i:intervals) {
            if (curr.start>i.end+1) {
                res.push_back(i);
                pos++;
            } else if (curr.end<i.start-1) {
                res.push_back(i);
            } else {
                curr.start=min(curr.start, i.start);
                curr.end=max(curr.end, i.end);
            }
        }
        res.insert(res.begin()+pos, curr);
        intervals=res;
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

