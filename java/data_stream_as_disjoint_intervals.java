/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class SummaryRanges {

    List<Interval> intervals;
    /** Initialize your data structure here. */
    public SummaryRanges() {
        intervals=new ArrayList<Interval>();
    }
    
    public void addNum(int val) {
        Interval newInterval=new Interval(val, val);
        List<Interval> res=new ArrayList<Interval>();
        int pos=0;
        for (int i=0; i<intervals.size(); i++) {
            if (intervals.get(i).end+1<newInterval.start) {
                res.add(intervals.get(i));
                pos++;
            } else if (intervals.get(i).start-1>newInterval.end) {
                res.add(intervals.get(i));
            } else {
                newInterval.start=Math.min(newInterval.start, intervals.get(i).start);
                newInterval.end=Math.max(newInterval.end, intervals.get(i).end);
            }
        }
        res.add(pos, newInterval);
        intervals=res;
    }
    
    public List<Interval> getIntervals() {
        return intervals;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * List<Interval> param_2 = obj.getIntervals();
 */
