356. Line Reflection 
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points.
If there is a line then it should be at y = (minX + maxX) / 2.
For each point, make sure that it has a reflected point in the opposite side.
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Hash Table Math
Hide Similar Problems (H) Max Points on a Line

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        set<pair<int,int>> pos;
        int xmin=INT_MAX, xmax=INT_MIN;
        
        for (auto p:points) {
            pos.insert(p);
            if (p.first<xmin) xmin=p.first;
            if (p.first>xmax) xmax=p.first;
        }
        
        double mid=(double)(xmin+xmax)/2;
        for (auto p:pos) {
            if (pos.find({2*mid-p.first, p.second})==pos.end()) return false;
        }
        
        return true;
    }
};
