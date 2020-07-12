1494. Parallel Courses II
Hard

164

20

Add to List

Share
Given the integer n representing the number of courses at some university labeled from 1 to n, and the array dependencies where dependencies[i] = [xi, yi]  represents a prerequisite relationship, that is, the course xi must be taken before the course yi.  Also, you are given the integer k.

In one semester you can take at most k courses as long as you have taken all the prerequisites for the courses you are taking.

Return the minimum number of semesters to take all courses. It is guaranteed that you can take all courses in some way.

 

Example 1:



Input: n = 4, dependencies = [[2,1],[3,1],[1,4]], k = 2
Output: 3 
Explanation: The figure above represents the given graph. In this case we can take courses 2 and 3 in the first semester, then take course 1 in the second semester and finally take course 4 in the third semester.
Example 2:



Input: n = 5, dependencies = [[2,1],[3,1],[4,1],[1,5]], k = 2
Output: 4 
Explanation: The figure above represents the given graph. In this case one optimal way to take all courses is: take courses 2 and 3 in the first semester and take course 4 in the second semester, then take course 1 in the third semester and finally take course 5 in the fourth semester.
Example 3:

Input: n = 11, dependencies = [], k = 2
Output: 6
 

Constraints:

1 <= n <= 15
1 <= k <= n
0 <= dependencies.length <= n * (n-1) / 2
dependencies[i].length == 2
1 <= xi, yi <= n
xi != yi
All prerequisite relationships are distinct, that is, dependencies[i] != dependencies[j].
The given graph is a directed acyclic graph.

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int m=1<<n;
        vector<int> dp(m, n), preq(n);
        dp[0]=0; 
        for (auto& d:dependencies) preq[d[1]-1] |= 1<<(d[0]-1);
        for (int i=0; i<m; ++i) {
            int cand=0;
            for (int j=0; j<n; ++j) {
                if ((i & preq[j])==preq[j] && (i & (1<<j))==0) cand |= 1<<j;
            }
            for (int c=cand; c>0; c=(c-1)&cand) {
                if (__builtin_popcount(c)<=k) {
                    dp[i|c]=min(dp[i|c], dp[i]+1);
                }
            }
        }
        return dp[m-1];
    }
};

