两个input：
1）desired time range to arrange a meeting -- TimeRange desired_time 
2）a list of busy intervals -- List<TimeRange> busy_intervals.

output: 
list of time ranges where a meeting can be scheduled, 会议没有时长限制 -- List<TimeRange>

struct Interval {
	int start;
	int end;
	Interval(int s, int e):start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> findMissingRanges(vector<Interval> intervals, int start, int end) {
		vector<Interval> res;
		int n=intervals.size();
		if (n==0) return res;
		sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){ return a.start<b.start; } );
		for (int i=0; i<n; i++) {
			if (intervals[i].start>=end) break;
			if (intervals[i].end<=start) continue;
			if (intervals[i].start>start) res.push_back(Interval(start, intervals[i].start));
			start=intervals[i].end;
		}

		if (start<end) res.push_back({start,end});
		return res;
	}
};

int main()
{
	Solution s;
	vector<Interval> intervals={Interval(1,2), Interval(3,6), Interval(5, 7), Interval(9,10)};
	vector<Interval> res=s.findMissingRanges(intervals, 2, 11);
	for (auto i:res) cout << i.start << " " << i.end << endl;

	return 0;
}

