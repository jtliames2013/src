539. Minimum Time Difference Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 5571
Total Submissions: 12234
Difficulty: Medium
Contributors:
fallcreek
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
Subscribe to see which companies asked this question.

Hide Tags

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        if (n==0) return 0;
        vector<pair<int,int>> times(n);
        for (int i=0; i<n; i++) {
            istringstream iss(timePoints[i]);
            char delim;
            iss >> times[i].first >> delim >> times[i].second;
        }
        sort(times.begin(), times.end());
        times.push_back({times[0].first+24, times[0].second});
        int res=INT_MAX;
        for (int i=0; i<n; i++) {
            res=min(res, (times[i+1].first-times[i].first)*60+(times[i+1].second-times[i].second));
        }
        
        return res;
    }
};

2. Use bucket
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        if (n==0) return 0;
        vector<bool> bucket(24*60);
        for (int i=0; i<n; i++) {
            int h, m;
            char delim;
            istringstream iss(timePoints[i]);
            iss >> h >> delim >> m;
            if (bucket[h*60+m]) return 0;
            bucket[h*60+m]=true;
        }
        int res=INT_MAX, prev=-1, first;
        for (int i=0; i<24*60; i++) {
            if (bucket[i]) {
                if (prev>=0) res=min(res, i-prev);
                else first=i;
                prev=i;
            }
        }
        res=min(res, first+24*60-prev);

        return res;
    }
};

