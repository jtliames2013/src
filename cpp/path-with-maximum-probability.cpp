1514. Path with Maximum Probability
Medium

152

3

Add to List

Share
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.

1. BFS
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, unordered_map<int, double>> graph;
        for (int i=0; i<edges.size(); ++i) {
            graph[edges[i][0]][edges[i][1]]=succProb[i];
            graph[edges[i][1]][edges[i][0]]=succProb[i];
        }
        vector<double> prob(n);
        prob[start]=1;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            auto f=q.front();
            q.pop();

            for (auto neighbor:graph[f]) {
                if (prob[f]*neighbor.second>prob[neighbor.first]) {
                    prob[neighbor.first]=prob[f]*neighbor.second;
                    q.push(neighbor.first);
                }
            }
        }

        return prob[end];
    }
};

2. Dijkstra
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, unordered_map<int, double>> graph;
        for (int i=0; i<edges.size(); ++i) {
            graph[edges[i][0]][edges[i][1]]=succProb[i];
            graph[edges[i][1]][edges[i][0]]=succProb[i];
        }
        vector<double> prob(n);
        prob[start]=-1;
        auto comp=[](pair<int, double>& a, pair<int, double>& b){ return a.second>b.second; };
        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(comp)> pq(comp);
        pq.push({start, -1});
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            if (prob[t.first]<t.second) continue;
            for (auto& iter:graph[t.first]) {
                if (prob[iter.first]>prob[t.first]*iter.second) {
                    prob[iter.first]=prob[t.first]*iter.second;
                    pq.push({iter.first, prob[iter.first]});
                }
            }
        }
        
        return -prob[end];
    }
};


