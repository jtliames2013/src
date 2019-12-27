253. Meeting Rooms II
Medium

1968

32

Add to List

Share
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

Facebook
|
21

Amazon
|
20

Microsoft
|
10

Bloomberg
|
10

Uber
|
9

Google
|
7

Oracle
|
7

Lyft
|
3

Quora
|
2

Postmates
|
2

Citrix
|
2

Apple
|
3

Atlassian
|
3

Yelp
|
2

Booking.com
|
2

Paypal
|
2

Drawbridge
|
2

Visa
|
2

GoDaddy
|
2

Snapchat
|
3

Cisco
|
3

Baidu
|
2

Walmart Labs
|
2

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        int res=0, count=0;
        vector<pair<int, bool>> points;
        for (auto& i:intervals) {
            points.push_back({i[0], true});
            points.push_back({i[1], false});
        }
        sort(points.begin(), points.end(), [](pair<int, bool>& a, pair<int, bool>& b){ return a.first<b.first || (a.first==b.first && a.second==false); });
        
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

