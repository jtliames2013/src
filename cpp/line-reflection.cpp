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
        set<pair<int, int>> st;
        int l=INT_MAX, r=INT_MIN;
        for (auto& p:points) {
            st.insert(p);
            l=min(l, p.first);
            r=max(r, p.first);
        }
        double mid=(l+r)/2.0;
        for (auto& p:st) {
            if (st.find({2*mid-p.first, p.second})==st.end()) return false;
        }
        
        return true;
    }
};

