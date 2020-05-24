1453. Maximum Number of Darts Inside of a Circular Dartboard
Hard

51

161

Add to List

Share
You have a very large square wall and a circular dartboard placed on the wall. You have been challenged to throw darts into the board blindfolded. Darts thrown at the wall are represented as an array of points on a 2D plane. 

Return the maximum number of points that are within or lie on any circular dartboard of radius r.

 

Example 1:



Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
Output: 4
Explanation: Circle dartboard with center in (0,0) and radius = 2 contain all points.
Example 2:



Input: points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
Output: 5
Explanation: Circle dartboard with center in (0,4) and radius = 5 contain all points except the point (7,8).
Example 3:

Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
Output: 1
Example 4:

Input: points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
Output: 4
 

Constraints:

1 <= points.length <= 100
points[i].length == 2
-10^4 <= points[i][0], points[i][1] <= 10^4
1 <= r <= 5000

POJ: http://poj.org/problem?id=1981
StackOverflow: https://stackoverflow.com/questions/3229459/algorithm-to-cover-maximal-number-of-points-with-one-circle-of-given-radius/3229582#3229582

class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int res=1, n=points.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                auto candidates=getCandidate(points[i], points[j], r);
                for (auto c:candidates) {
                    int cnt=0;
                    for (auto& p:points) {
                        if ((p[0]-c[0])*(p[0]-c[0])+(p[1]-c[1])*(p[1]-c[1])<=r*r+1e-6) cnt++;
                    }
                    res=max(res, cnt);
                }
            }
        }

        return res;
    }
private:
    vector<vector<double>> getCandidate(vector<int>& p1, vector<int>& p2, int r) {
        double dx=p2[0]-p1[0], dy=p2[1]-p1[1];
        double d=sqrt(dx*dx+dy*dy);
        if (d>2.0*r) return vector<vector<double>>();
        double c1=(p1[0]+p2[0])/2.0, c2=(p1[1]+p2[1])/2.0;
        double len=sqrt(r*r-(d/2)*(d/2));
        return {{c1-len*dy/d, c2+len*dx/d}, {c1+len*dy/d, c2-len*dx/d}};
    }
};

