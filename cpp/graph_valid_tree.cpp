261. Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Hide Company Tags Google Facebook Zenefits
Hide Tags Depth-first Search Breadth-first Search Graph Union Find
Hide Similar Problems (M) Course Schedule (M) Number of Connected Components in an Undirected Graph

// NOTE: visited has 3 states, white, gray, and black

1. BFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> visited(n);
        unordered_map<int, unordered_set<int>> graph;
        for (auto& e:edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        queue<int> q;
        q.push(0);
        visited[0]=1;
        
        while (!q.empty()) {
            int f=q.front();
            q.pop();
            
            for (auto neighbor:graph[f]) {
                if (visited[neighbor]==1) return false;
                if (visited[neighbor]==0) {
                    q.push(neighbor);
                    visited[neighbor]=1;
                }
            }
            visited[f]=2;
        }
        
        for (auto v:visited) {
            if (v==0) return false;
        }
        return true;
    }
};

2. DFS
class Solution {
public:
    bool dfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& visited, int curr, int parent) {
        visited[curr]=1;
        for (auto neighbor:graph[curr]) {
            if (neighbor==parent) continue;
            if (visited[neighbor]==1) return false;
            if (visited[neighbor]==0) {
                if (dfs(graph, visited, neighbor, curr)==false) {
                    return false;
                }
            }
        }
        
        visited[curr]=2;
        return true;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> visited(n);
        unordered_map<int, unordered_set<int>> graph;
        for (auto& e:edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
    
        if (dfs(graph, visited, 0, -1)==false) return false;
        
        for (auto v:visited) {
            if (v==0) return false;
        }
        return true;
    }
};

3. union-find
class Solution {
public:
    int find (vector<int>& parent, int i) {
        while (parent[i]!=i) i=parent[i];
        return i;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n);
        for (int i=0; i<n; i++) parent[i]=i;
        
        for (auto& e:edges) {
            int p1=find(parent, e.first);
            int p2=find(parent, e.second);
            if (p1==p2) return false;
            parent[p2]=p1;
        }
        return edges.size()==n-1;
    }    
};

