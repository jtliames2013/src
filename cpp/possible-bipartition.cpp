886. Possible Bipartition
Medium

344

16

Favorite

Share
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

1. BFS
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N<=0) return false;
        vector<unordered_set<int>> graph(N);
        for (auto& d:dislikes) {
            graph[d[0]-1].insert(d[1]-1);
            graph[d[1]-1].insert(d[0]-1);
        }

        queue<int> q;
        vector<int> partition(N);        
        for (int i=0; i<N; ++i) {
            if (partition[i]==0) {
                q.push(i);
                partition[i]=1;
                while (!q.empty()) {
                    auto f=q.front();
                    q.pop();
                    for (auto neighbor:graph[f]) {
                        if (partition[neighbor]==partition[f]) return false;
                        else if (partition[neighbor]==0) {
                            partition[neighbor]=-partition[f];
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return true;
    }
};

2. DFS
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N<=0) return false;
        vector<unordered_set<int>> graph(N);
        for (auto& d:dislikes) {
            graph[d[0]-1].insert(d[1]-1);
            graph[d[1]-1].insert(d[0]-1);
        }

        queue<int> q;
        vector<int> partition(N);        
        for (int i=0; i<N; ++i) {
            if (partition[i]==0) {
                partition[i]=1;
                if (!dfs(graph, partition, i)) return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<unordered_set<int>>& graph, vector<int>& partition, int start) {
        for (auto neighbor:graph[start]) {
            if (partition[neighbor]==partition[start]) return false;
            else if (partition[neighbor]==0) {
                partition[neighbor]=-partition[start];
                if (!dfs(graph, partition, neighbor)) return false;
            }
        }
        return true;
    }
};
