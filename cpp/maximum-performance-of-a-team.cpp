1383. Maximum Performance of a Team
Hard

6

2

Add to List

Share
There are n engineers numbered from 1 to n and two arrays: speed and efficiency, where speed[i] and efficiency[i] represent the speed and efficiency for the i-th engineer respectively. Return the maximum performance of a team composed of at most k engineers, since the answer can be a huge number, return this modulo 10^9 + 7.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers. 

 

Example 1:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
Example 2:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
Example 3:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
 

Constraints:

1 <= n <= 10^5
speed.length == n
efficiency.length == n
1 <= speed[i] <= 10^5
1 <= efficiency[i] <= 10^8
1 <= k <= n

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long res=0, sum=0;
        vector<pair<int,int>> combo(n);
        for (int i=0; i<n; ++i) combo[i]={speed[i], efficiency[i]};
        sort(combo.begin(), combo.end(), [](pair<int,int>& a, pair<int,int>& b){ return a.second>b.second; });
        priority_queue<long, vector<long>, greater<long>> pq;
        for (int i=0; i<n; ++i) {
            pq.push(combo[i].first);
            sum+=combo[i].first;
            while (pq.size()>k) {
                sum-=pq.top();
                pq.pop();
            }
            res=max(res, sum*combo[i].second);
        }

        return res%mod;
    }
private:
    const int mod=1e9+7;
};

