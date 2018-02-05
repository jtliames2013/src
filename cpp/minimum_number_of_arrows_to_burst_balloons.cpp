452. Minimum Number of Arrows to Burst Balloons   QuestionEditorial Solution  My Submissions
Total Accepted: 1666 Total Submissions: 3957 Difficulty: Medium Contributors: abhijeeg
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
Subscribe to see which companies asked this question

Hide Tags Greedy
Hide Similar Problems (M) Meeting Rooms II (M) Non-overlapping Intervals

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n=points.size();
        if (n==0) return 0;
        
        sort(points.begin(), points.end(), [](pair<int,int>& a, pair<int,int>& b) { return a.second<b.second || (a.second==b.second&&a.first<b.first); } );
        
        int res=1, end=points[0].second;
        for (int i=1; i<n; i++) {
            if (points[i].first>end) {
                end=points[i].second;
                res++;
            }
        }
        
        return res;
    }
};

2.
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n=points.size();
        if (n==0) return 0;
        sort(points.begin(), points.end(), [](pair<int,int>& a, pair<int,int>& b) { return a.second<b.second; });
        int end=points[0].second, count=0;
        for (int i=1; i<n; i++) {
            if (points[i].first<=end) count++;
            else end=points[i].second;
        }
        return n-count;
    }
};
