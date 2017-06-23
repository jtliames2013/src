253. Meeting Rooms II 
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

Hide Company Tags Google Facebook
Hide Tags Heap Greedy Sort
Hide Similar Problems (H) Merge Intervals (E) Meeting Rooms

NOTE: sort an array of both start and end points. if start of point 1 equals end of point 2, then point 2 comes first.

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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        vector<pair<int,bool>> points;
        for (auto& i:intervals) {
            points.push_back({i.start, true});
            points.push_back({i.end, false});
        }
        sort(points.begin(), points.end(), [](pair<int,bool>& a, pair<int,bool>& b) { return a.first<b.first || (a.first==b.first && a.second==false); } );
        
        int res=0, count=0;
        for (auto& p:points) {
            if (p.second) count++;
            else count--;
            res=max(res, count);
        }
        
        return res;
    }
};

2. return all the empty intervals
class Solution {
public:
	vector<Interval> minMeetingRooms(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        vector<pair<int,bool>> points;
        for (auto& i:intervals) {
            points.push_back({i.start, true});
            points.push_back({i.end, false});
        }
        sort(points.begin(), points.end(), [](pair<int,bool>& a, pair<int,bool>& b) { return a.first<b.first || (a.first==b.first && a.second==false); } );

        int count=0, start=-1, end;
        for (auto& p:points) {
            if (p.second) count++;
            else count--;
            if (count==0) start=p.first;
            else if (count==1) {
            	end=p.first;
            	if (start!=-1 && end>start) res.push_back(Interval(start,end));
            } else {
            	start=-1;
            }
        }

        return res;
    }
};

void printInterval(vector<Interval> intervals) {
	for (auto& i:intervals) {
		cout << i.start << " " << i.end << endl;
	}
}

int main()
{
	Solution s;
	//vector<Interval> intervals={Interval(1, 2), Interval(3, 6), Interval(4, 5), Interval(7, 8), Interval(9, 10)};
	vector<Interval> intervals={Interval(1, 2), Interval(3, 6), Interval(4, 5), Interval(5, 8), Interval(9, 10)};
	vector<Interval> res=s.minMeetingRooms(intervals);
	printInterval(res);

	return 0;
}

3. return all the maximum overlapped intervals
class Solution {
public:
	vector<Interval> minMeetingRooms(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        vector<pair<int,bool>> points;
        for (auto& i:intervals) {
            points.push_back({i.start, true});
            points.push_back({i.end, false});
        }
        sort(points.begin(), points.end(), [](pair<int,bool>& a, pair<int,bool>& b) { return a.first<b.first || (a.first==b.first && a.second==false); } );

        int count=0, start=-1, end, maxCnt=0;
        for (auto& p:points) {
            if (p.second) count++;
            else count--;
            if (count>maxCnt) {
            	res.clear();
            	maxCnt=count;
            	start=p.first;
            } else if (count==maxCnt) {
            	start=p.first;
            } else if (count==maxCnt-1) {
            	if (start!=-1) res.push_back(Interval(start, p.first));
            	start=-1;
            }
        }

        return res;
    }
};

void printInterval(vector<Interval> intervals) {
	for (auto& i:intervals) {
		cout << i.start << " " << i.end << endl;
	}
}

int main()
{
	Solution s;
	vector<Interval> intervals={Interval(1, 2), Interval(3, 6), Interval(4, 5), Interval(7, 8), Interval(9, 10)};
	//vector<Interval> intervals={Interval(1, 10), Interval(2, 8), Interval(3, 4), Interval(5, 6), Interval(8, 10)};
	vector<Interval> res=s.minMeetingRooms(intervals);
	printInterval(res);

	return 0;
}

