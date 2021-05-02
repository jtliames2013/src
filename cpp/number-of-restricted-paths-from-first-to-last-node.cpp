1786. Number of Restricted Paths From First to Last Node
Medium

263

48

Add to List

Share
There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.

A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.

The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.

Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.

 

Example 1:


Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
Output: 3
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5
Example 2:


Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
Output: 1
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.
 

Constraints:

1 <= n <= 2 * 104
n - 1 <= edges.length <= 4 * 104
edges[i].length == 3
1 <= ui, vi <= n
ui != vi
1 <= weighti <= 105
There is at most one edge between any two nodes.
There is at least one path between any two nodes.

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {        
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto& e:edges) {
            graph[e[0]-1][e[1]-1]=e[2];
            graph[e[1]-1][e[0]-1]=e[2];
        }
        vector<int> dist(n, INT_MAX);
        dist[n-1]=0;
        auto cmp=[](vector<int>& a, vector<int>& b){ return a[0]>b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({0, n-1});
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            int d=t[0], u=t[1];
            if (dist[u]<d) continue;
            for (auto& iter:graph[t[1]]) {
                int v=iter.first, w=iter.second;
                if (dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        vector<int> dp(n, -1);
        return dfs(0, n, graph, dp, dist);
    }
private:
    const int mod=1e9+7;
    
    int dfs(int u, int n, unordered_map<int, unordered_map<int, int>>& graph, vector<int>& dp, vector<int>& dist) {
        if (u==n-1) return 1;
        if (dp[u]!=-1) return dp[u];
        int res=0;
        for (auto& iter:graph[u]) {
            if (dist[iter.first]<dist[u]) res=(res+dfs(iter.first, n, graph, dp, dist))%mod;
        }
        
        dp[u]=res;
        return dp[u];
    }
};

