phone 1: get a list of conflicting time for meetings, 有点类似leetcode 的meeting rooms, 区别是要列出每个slot里面conflict 的meeting有哪些。我当时想了一个很复杂的方法，最后编不出来。。。后来在面试官的提示下用直接bruteforce 每个slot出来了。。。这里非常感谢面我的第一个小哥。因为我当时觉得我已经挂了，可是他让我过了。。。

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Point {
	int time;
	bool isStart;
	int meeting;
	Point(int t, bool b, int m): time(t), isStart(b), meeting(m) {}
};

struct Slot {
	int start;
	int end;
	set<int> meetings;
	Slot(int s, int e, set<int> m):start(s), end(e), meetings(m) {}
};

class Solution {
public:
	vector<Slot> getConflictTimes(vector<Interval>& intervals) {
		vector<Slot> res;
		int n=intervals.size();
		if (n==0) return res;
		vector<Point> times;
		for (int i=0; i<intervals.size(); i++) {
			times.push_back(Point(intervals[i].start, true, i));
			times.push_back(Point(intervals[i].end, false, i));
		}
		sort(times.begin(), times.end(), [](Point a, Point b)
			 { return a.time<b.time || (a.time==b.time && a.isStart==false); });

		int count=0;
		int start, end;
		set<int> meetings;
		for (int i=0; i<times.size(); i++) {
			if (times[i].isStart==true) {
				count++;
				if (count==2) {
					start=times[i].time;
				} else if (count>2) {
					end=times[i].time;
					res.push_back(Slot(start,end, meetings));
					start=end;
				}
				meetings.insert(times[i].meeting);
			} else {
				count--;
				if (count>=1) {
					end=times[i].time;
					res.push_back(Slot(start,end, meetings));
					if (count>=2) {
						start=end;
					}
				}
				meetings.erase(times[i].meeting);
			}
		}

		return res;
	}
};

int main() {
	Solution s;
	vector<Interval> intervals={Interval(0,5), Interval(2,7), Interval(3,9), Interval(6,10)};
	vector<Slot> res=s.getConflictTimes(intervals);
	return 0;
}

