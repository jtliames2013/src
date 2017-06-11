149. Max Points on a Line 

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n=points.size();
        if (n==0) return 0;
        int res=0;
        
        for (int i=0; i<n; i++) {
            unordered_map<double,int> slopes;
    		// include itself and any point that is the same        
            int numsame=1;
            int localmax=0;
            double slope;
            
            for (int j=i+1; j<n; j++) {
                if (points[j].x==points[i].x && points[j].y==points[i].y) {
                    numsame++;
                } else {
                    if (points[j].x==points[i].x) {
                        slope=INT_MAX;
                    } else {
                        slope=double(points[j].y-points[i].y)/double(points[j].x-points[i].x);
                    }
                    slopes[slope]++;
                }
            }
            for (auto s:slopes) localmax=max(localmax, s.second);
            localmax+=numsame;
            res=max(res, localmax);
        }
        
        return res;
    }
};

