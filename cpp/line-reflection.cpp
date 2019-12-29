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

Amazon
|
2

Google
|
LeetCode

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        set<vector<int>> st;
        int l=INT_MAX, r=INT_MIN;
        for (auto& p:points) {
            st.insert(p);
            l=min(l, p[0]);
            r=max(r, p[0]);
        }
        double mid=(l+r)/2.0;
        for (auto& iter:st) {
            if (st.find({2*mid-iter[0], iter[1]})==st.end()) return false;
        }
        return true;
    }
};

