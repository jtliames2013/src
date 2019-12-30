759. Employee Free Time
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Note:

schedule and schedule[i] are lists with lengths in range [1, 50].
0 <= schedule[i].start < schedule[i].end <= 10^8.

Pinterest
|
11

Amazon
|
7

Airbnb
|
3

DoorDash
|
3

Uber
|
2

Google
|
2

Microsoft
|
2

Intuit
|
2

Bloomberg
|
2

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        map<int, int> points;
        for (auto& s:schedule) {
            for (auto& i:s) {
                points[i.start]++;
                points[i.end]--;
            }
        }

        int cnt=0, start=-1;
        for(auto& p:points) {
            cnt+=p.second;
            if (cnt==0) start=p.first;
            else {
                if (start!=-1) {
                    res.push_back(Interval(start, p.first));
                    start=-1;
                }
            }
        }

        return res;
    }
};

