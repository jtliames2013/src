1192. Critical Connections in a Network
Hard

243

26

Favorite

Share
There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.

https://en.wikipedia.org/wiki/Bridge_(graph_theory)
https://stackoverflow.com/questions/11218746/bridges-in-a-connected-graph/11221469#11221469

The array pre is like the visited array in the dfs algorithm; but instead of just flagging that the vertex as visited, we identify each vertex with a different number (according to its position in the dfs tree). The low array helps to identify if there is a loop. The low array identifies the lowest numbered (from pre array) vertex that the current vertex can reach.

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<unordered_set<int>> graph(n);
        vector<int> pre(n,-1), low(n,-1);
        for (auto& c:connections) {
            graph[c[0]].insert(c[1]);
            graph[c[1]].insert(c[0]);
        }
        
        dfs(res, graph, pre, low, 0, -1, 0);
        
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<unordered_set<int>>& graph, vector<int>& pre, vector<int>& low, int curr, int parent, int label) {                    
        pre[curr]=low[curr]=label;
        for (auto neighbor:graph[curr]) {
            if (pre[neighbor]==-1) {
                dfs(res, graph, pre, low, neighbor, curr, label+1);
                low[curr]=min(low[curr], low[neighbor]);
                if (low[neighbor]>pre[curr]) res.push_back({curr, neighbor});
            } else if (neighbor!=parent) {
                low[curr]=min(low[curr], pre[neighbor]);
            }
        }        
    }
};

