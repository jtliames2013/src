149. Max Points on a Line 

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if (n==0) return 0;
        int res=0;
        
        for (int i=0; i<n; i++) {
            unordered_map<double, int> slopes;
	    // include itself and any point that is the same        
            int numsame=1;
            int localmax=0;
            double slope;
            
            for (int j=i+1; j<n; j++) {
                if (points[j][0]==points[i][0] && points[j][1]==points[i][1]) {
                    numsame++;
                } else {
                    if (points[j][0]==points[i][0]) {
                        slope=INT_MAX;
                    } else {
                        // times 10 to work around precision, should use precision library
                        slope=double(points[j][1]-points[i][1])*10/double(points[j][0]-points[i][0]);     
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

