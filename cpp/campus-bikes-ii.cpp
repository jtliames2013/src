1066. Campus Bikes II
Medium

272

20

Favorite

Share
On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the Manhattan distances between each worker and their assigned bike is minimized.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.

 

Example 1:



Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: 6
Explanation: 
We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of both assignments is 3, so the output is 6.
Example 2:



Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: 4
Explanation: 
We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the Manhattan distances as 4.
 

Note:

0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000
All worker and bike locations are distinct.
1 <= workers.length <= bikes.length <= 10

Google
|
6

Amazon
|
3

1. priority queue
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m=workers.size(), n=bikes.size();
        auto comp=[](vector<int>& a, vector<int>& b){ return a[0]>b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        unordered_set<int> st;
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {            
            int cost=pq.top()[0], i=pq.top()[1], state=pq.top()[2];
            pq.pop();            
            if (st.find(state)!=st.end()) continue;
            st.insert(state);
            if (i==m) return cost;
            for (int j=0; j<n; ++j) {
                if (((1<<j) & state)==0) {
                    int dist=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                    pq.push({cost+dist, i+1, (1<<j) | state});
                }
            }
        }
        return 0;
    }
};

2. DP
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int res=INT_MAX, m=workers.size(), n=bikes.size();
        vector<vector<int>> dp(m+1, vector<int>(1<<n, INT_MAX));
        dp[0][0]=0;
        for (int i=1; i<=m; ++i) {
            for (int state=1; state<(1<<n); ++state) {
                if (bitCount(state)!=i) continue;
                for (int j=0; j<n; ++j) {
                    if ((state & (1<<j))!=0) {
                        int prev=state ^ (1<<j);
                        int dist=abs(workers[i-1][0]-bikes[j][0])+abs(workers[i-1][1]-bikes[j][1]);
                        dp[i][state]=min(dp[i][state], dp[i-1][prev]+dist);

                        if (i==m) res=min(res, dp[i][state]);
                    }
                }
            }
        }

        return res;
    }
private:
    int bitCount(int n) {
        int res=0;
        while (n>0) {
            n&=(n-1);
            res++;
        }
        return res;
    }
};

