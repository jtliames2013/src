323. Number of Connected Components in an Undirected Graph 
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

     0          3
     |          |
     1 --- 2    4

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:

     0           4
     |           |
     1 --- 2 --- 3

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges. 

1. BFS
class Solution {
public:
    void bfs(unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited, int i) {
        queue<int> q;
        q.push(i);
        visited[i]=true;
        
        while (!q.empty()) {
            int f=q.front();
            q.pop();
            
            for (auto neighbor:graph[f]) {
                if (visited[neighbor]==false) {
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& e:edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        vector<bool> visited(n);
        
        int res=0;
        for (int i=0; i<n; i++) {
            if (visited[i]==false) {
                res++;
                bfs(graph, visited, i);
            }
        }
        return res;
    }
};

2. DFS
class Solution {
public:
    void dfs(unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited, int i) {
        visited[i]=true;
        
        for (auto neighbor:graph[i]) {
            if (visited[neighbor]==false) {
                dfs(graph, visited, neighbor);
            }
        }
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& e:edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        vector<bool> visited(n);
        
        int res=0;
        for (int i=0; i<n; i++) {
            if (visited[i]==false) {
                res++;
                dfs(graph, visited, i);
            }
        }
        return res;
    }
};

3. union-find
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parents(n);
        for (int i=0; i<n; i++) parents[i]=i;

        for (auto& e:edges) {
            int p1=find(parents, e.first);
            int p2=find(parents, e.second);
            if (p1!=p2) {
                parents[p2]=p1;
                n--;
            }
        }
        
        return n;
    }
    
    int find(vector<int>& parents, int i) {
        while (parents[i]!=i) {
            parents[i]=parents[parents[i]];
            i=parents[i];
        }
        return i;
        /* if (parents[i]!=i) {
            parents[i]=find(parents, parents[i]);
        }
        return parents[i]; */
    }
};

