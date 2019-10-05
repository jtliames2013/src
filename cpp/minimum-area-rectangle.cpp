939. Minimum Area Rectangle
Medium

361

69

Favorite

Share
Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res=INT_MAX, n=points.size();
        unordered_map<int, set<int>> mp;
        for (auto& p:points) mp[p[0]].insert(p[1]);
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (points[i][0]==points[j][0] || points[i][1]==points[j][1]) continue;
                if (mp[points[i][0]].find(points[j][1])!=mp[points[i][0]].end() &&
                    mp[points[j][0]].find(points[i][1])!=mp[points[j][0]].end()) {
                    res=min(res, abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                }
            }
        }
        return res==INT_MAX?0:res;
    }
};
