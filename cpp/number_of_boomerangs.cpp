447. Number of Boomerangs   QuestionEditorial Solution  My Submissions
Total Accepted: 2153 Total Submissions: 5565 Difficulty: Easy Contributors: alexander54
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
Subscribe to see which companies asked this question

Hide Tags Hash Table
Hide Similar Problems (M) Line Reflection

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res=0;
        for (int i=0; i<points.size(); i++) {
            unordered_map<double, int> table;
            for (int j=0; j<points.size(); j++) {
                if (i!=j) {
                    res+=2*table[hypot(points[i].first-points[j].first, points[i].second-points[j].second)]++;
                }
            }
        }
        return res;
    }
};

