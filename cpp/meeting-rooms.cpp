252. Meeting Rooms
Easy

434

30

Favorite

Share
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

Amazon
|
4

Google
|
2

Microsoft
|
2

Bloomberg
|
2

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if (n==0) return true;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[0]<b[0]; });

        for (int i=0; i<n-1; ++i) {
            if (intervals[i][1]>intervals[i+1][0]) return false;
        }
        return true;
    }
};

