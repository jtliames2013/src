774. Minimize Max Distance to Gas Station
Hard

280

41

Add to List

Share
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:

stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.

Google
|
2

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n=stations.size(), cnt;
        double l=0, r=stations[n-1]-stations[0], mid;
        while (r-l>1e-6) {
            mid=(r+l)/2;
            cnt=0;
            for (int i=1; i<n; ++i) {
                cnt+=ceil((stations[i]-stations[i-1])/mid)-1;
            }
            if (cnt<=K) r=mid;
            else l=mid;
        }
        return l;
    }
};

