1335. Minimum Difficulty of a Job Schedule
Hard

37

2

Add to List

Share
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done in that day.

Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

 

Example 1:


Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
Example 4:

Input: jobDifficulty = [7,1,7,1,7,1], d = 3
Output: 15
Example 5:

Input: jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
Output: 843
 

Constraints:

1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10

1. DFS
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if (n<d) return -1;
        unordered_map<int, int> mp;
        return dfs(jobDifficulty, mp, 0, n, d);
    }
private:
    int dfs(vector<int>& jobDifficulty, unordered_map<int, int>& mp, int start, int n, int d) {
        if (d==1) {
            return *max_element(jobDifficulty.begin()+start, jobDifficulty.end());
        }

        int key=(start<<16) | d;
        if (mp.find(key)!=mp.end()) return mp[key];

        mp[key]=INT_MAX;
        int mx=INT_MIN;
        for (int i=start; i<=n-d; ++i) {
            mx=max(mx, jobDifficulty[i]);
            mp[key]=min(mp[key], mx+dfs(jobDifficulty, mp, i+1, n, d-1));
        }
        return mp[key];
    }
};

2. DP
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if (n<d) return -1;
        vector<vector<int>> dp(d, vector<int>(n));
        int mx=INT_MIN;
        for (int i=0; i<n; ++i) {
            mx=max(mx, jobDifficulty[i]);
            dp[0][i]=mx;
        }
        for (int i=1; i<d; ++i) {
            for (int j=i; j<n; ++j) {
                dp[i][j]=INT_MAX;
                mx=jobDifficulty[j];
                for (int k=j-1; k>=i-1; --k) {
                    dp[i][j]=min(dp[i][j], dp[i-1][k]+mx);
                    mx=max(mx, jobDifficulty[k]);
                }
            }
        }
        return dp[d-1][n-1];
    }
};

