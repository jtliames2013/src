1272. Remove Interval
Medium

37

4

Favorite

Share
Given a sorted list of disjoint intervals, each interval intervals[i] = [a, b] represents the set of real numbers x such that a <= x < b.

We remove the intersections between any interval in intervals and the interval toBeRemoved.

Return a sorted list of intervals after all such removals.

 

Example 1:

Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
Output: [[0,1],[6,7]]
Example 2:

Input: intervals = [[0,5]], toBeRemoved = [2,3]
Output: [[0,2],[3,5]]
 

Constraints:

1 <= intervals.length <= 10^4
-10^9 <= intervals[i][0] < intervals[i][1] <= 10^9

Google
|
LeetCode

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        int n=intervals.size();
        for (int i=0; i<n; ++i) {
            if (intervals[i][1]<=toBeRemoved[0] || intervals[i][0]>=toBeRemoved[1]) res.push_back(intervals[i]);
            else {
                if (intervals[i][0]<toBeRemoved[0]) res.push_back({intervals[i][0], toBeRemoved[0]});
                if (intervals[i][1]>toBeRemoved[1]) res.push_back({toBeRemoved[1], intervals[i][1]});
            }
        }
        
        return res;
    }
};

