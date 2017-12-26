743. Network Delay Time
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.

1. Djikstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto& time:times) {
            graph[time[0]-1][time[1]-1]=time[2];            
        }
        vector<int> dist(N, INT_MAX);
        dist[K-1]=0;
        auto comp=[](pair<int,int>& a, pair<int,int>& b) { return a.second>b.second; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        pq.push({K-1,0});
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            if (dist[t.first]<t.second) continue;
            for (auto neighbor:graph[t.first]) {
                if (dist[neighbor.first]>t.second+graph[t.first][neighbor.first]) {
                    dist[neighbor.first]=t.second+graph[t.first][neighbor.first];
                    pq.push({neighbor.first,dist[neighbor.first]});
                }
            }
        }
        int res=0;
        for (auto d:dist) {
            if (d==INT_MAX) return -1;
            else if (d>res) res=d;
        }
        return res;
    }
};
