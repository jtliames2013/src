787. Cheapest Flights Within K Stops
DescriptionHintsSubmissionsDiscussSolution
There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
Note:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.

1. bellman ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        K++;
        vector<long> dp(n, INT_MAX);
        dp[src]=0;
        
        for (int i=1; i<=K; ++i) {
            vector<long> next=dp;
            for (auto& f:flights) {
                next[f[1]]=min(next[f[1]], dp[f[0]]+f[2]);
            }
            dp=next;
        }
        return dp[dst]==INT_MAX?-1:dp[dst];
    }
};

2. Dijkstra
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto& f:flights) graph[f[0]].push_back({f[1], f[2]});
        auto comp=[](vector<int>& a, vector<int>& b){ return a[0]>b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        pq.push({0, src, K+1}); //{cost, dest, stops}
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            if (t[1]==dst) return t[0];
            if (t[2]==0) continue;
            for (auto neighbor:graph[t[1]]) {
                pq.push({t[0]+neighbor.second, neighbor.first, t[2]-1});
            }
        }
        return -1;
    }
};
