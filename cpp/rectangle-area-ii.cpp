850. Rectangle Area II
Hard

234

24

Favorite

Share
We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1, y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the ith rectangle.

Find the total area covered by all rectangles in the plane.  Since the answer may be too large, return it modulo 10^9 + 7.



Example 1:

Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: As illustrated in the picture.
Example 2:

Input: [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 = (-7)^2 = 49.
Note:

1 <= rectangles.length <= 200
rectanges[i].length = 4
0 <= rectangles[i][j] <= 10^9
The total area covered by all rectangles will never exceed 2^63 - 1 and thus will fit in a 64-bit signed integer.

Approach #3: Line Sweep
Intuition

Imagine we pass a horizontal line from bottom to top over the shape. We have some active intervals on this horizontal line, which gets updated twice for each rectangle. In total, there are 2 * N2∗N events, and we can update our (up to NN) active horizontal intervals for each update.

Algorithm

For a rectangle like rec = [1,0,3,1], the first update is to add [1, 3] to the active set at y = 0, and the second update is to remove [1, 3] at y = 1. Note that adding and removing respects multiplicity - if we also added [0, 2] at y = 0, then removing [1, 3] at y = 1 will still leave us with [0, 2] active.

This gives us a plan: create these two events for each rectangle, then process all the events in sorted order of y. The issue now is deciding how to process the events add(x1, x2) and remove(x1, x2) such that we are able to query() the total horizontal length of our active intervals.

We can use the fact that our remove(...) operation will always be on an interval that was previously added. Let's store all the (x1, x2) intervals in sorted order. Then, we can query() in linear time using a technique similar to a classic LeetCode problem, Merge Intervals.

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int res=0, i=0;
        vector<vector<int>> points(rectangles.size()*2);
        for (auto& r:rectangles) {
            points[i++]={r[1], r[0], r[2], 1};
            points[i++]={r[3], r[0], r[2], -1};
        }
        
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>& b){ return a[0]<b[0]; });
        
        multiset<vector<int>> intervals;
        int prevY=0, currY;
        for (auto& p:points) {
            currY=p[0];
            long len=0;
            int start=-1, end=-1;
            for (auto& interval:intervals) {
                if (interval[0]>end) {
                    len+=end-start;
                    start=interval[0];
                    end=interval[1];
                } else {
                    end=max(end, interval[1]);
                }
            }
            len+=end-start;
            res=(res+len*(currY-prevY))%mod;
            
            if (p[3]==1) {
                intervals.insert({p[1], p[2]});
            } else {
                intervals.erase(intervals.lower_bound({p[1], p[2]}));
            }
            prevY=currY;
        }
        return res;
    }
private:
    const int mod=1e9+7;
};

