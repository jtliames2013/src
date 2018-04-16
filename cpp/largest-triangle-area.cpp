812. Largest Triangle Area
DescriptionHintsSubmissionsDiscussSolution
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.

https://www.mathopenref.com/coordtrianglearea.html
class Solution {
public:
    double area(vector<int>& a, vector<int>& b, vector<int>& c) {
        return 0.5*abs(a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]));
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        double res=0;
        int n=points.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    res=max(res, area(points[i], points[j], points[k]));
                }
            }
        }
        return res;        
    }
};
