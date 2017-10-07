Find least number of intervals from A that can fully cover B
For example:
Given A=[[0,3],[3,4],[4,6],[2,7]] B=[0,6] return 2 since we can use [0,3] [2,7] to cover the B
Given A=[[0,3],[4,7]] B=[0,6] return 0 since we cannot find any interval combination from A to cover the B

We sort the array by start time. Each time we select greedily an interval which starts at or before current start point point and is the farthest interval.
for example .
[0,3],[2,7][3,4][4,6]

we select 0,3 because this is the only option
we make a choice between [2,7], [3,4] and takes [2,7] because 7-3 > 4-3
So we choose 2 intervals

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> minimumCoverInterval(vector<Interval> intervals, Interval target) {
		vector<Interval> res;
		int n=intervals.size();
		if (n==0) return res;
		sort(intervals.begin(), intervals.end(), [](Interval& a, Interval &b) { return a.start < b.start; } );
		int start=target.start;
		int i=0;
		while (i<n) {
			if (start>target.end) break;
			int end=0, idx=-1;
			while (i<n && intervals[i].start<=start) {
				if (intervals[i].end>end) {
					end=intervals[i].end;
					idx=i;
				}
				i++;
			}
			if (idx==-1 || intervals[idx].end<start) return vector<Interval>();

			res.push_back(intervals[idx]);
			start=intervals[idx].end;
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<Interval> a={Interval(1,3), Interval(3,4), Interval(4,6), Interval(2,7)};
	Interval b(0,6);
	vector<Interval> res=s.minimumCoverInterval(a, b);
	for (auto i:res) cout << "[" << i.start << "," << i.end<< "]";
	cout << endl;
	return 0;
}

