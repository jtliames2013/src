963. Minimum Area Rectangle II
Medium

83

131

Favorite

Share
Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:



Input: [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
Example 2:



Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
Example 3:



Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.
Example 4:



Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
 

Note:

1 <= points.length <= 50
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
Answers within 10^-5 of the actual value will be accepted as correct.

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n=points.size();
        if (n<4) return 0;
        double res=DBL_MAX;
        unordered_map<string,vector<vector<int>>> mp;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                long dist=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                double centerX=(points[i][0]+points[j][0])/2.0;
                double centerY=(points[i][1]+points[j][1])/2.0;
                string key=to_string(dist)+","+to_string(centerX)+","+to_string(centerY);
                mp[key].push_back({i, j});
            }
        }
        
        for (auto iter:mp) {
            for (int i=0; i<iter.second.size(); ++i) {
                for (int j=i+1; j<iter.second.size(); ++j) {
                    int p1=iter.second[i][0];
                    int p2=iter.second[i][1];
                    int p3=iter.second[j][0];
                    double len1=sqrt((points[p1][0]-points[p3][0])*(points[p1][0]-points[p3][0])+(points[p1][1]-points[p3][1])*(points[p1][1]-points[p3][1]));
                    double len2=sqrt((points[p2][0]-points[p3][0])*(points[p2][0]-points[p3][0])+(points[p2][1]-points[p3][1])*(points[p2][1]-points[p3][1]));
                    res=min(res, len1*len2);
                }
            }
        }
        
        return res==DBL_MAX?0:res;
    }
};
