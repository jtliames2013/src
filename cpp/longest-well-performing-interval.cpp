1124. Longest Well-Performing Interval
Medium

227

44

Favorite

Share
We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

 

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
 

Constraints:

1 <= hours.length <= 10000
0 <= hours[i] <= 16

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res=0, n=hours.size(), count=0;
        unordered_map<int,int> mp;
        for (int i=0; i<n; ++i) {
            count+=hours[i]>8?1:-1;
            if (count>0) res=i+1;
            else {
                if (mp.find(count)==mp.end()) mp[count]=i;
                if (mp.find(count-1)!=mp.end()) res=max(res, i-mp[count-1]);
            }
        }
        return res;
    }
};

