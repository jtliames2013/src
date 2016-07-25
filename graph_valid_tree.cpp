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


#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;

// NOTE: visited has 3 states, white, gray, and black

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        map<int, unordered_set<int> > graph;
        map<int, int> visited;
        for (auto e:edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
      
        // BFS
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while (!q.empty()) {
            int i=q.front();
            q.pop();

            for (auto n:graph[i]) {
                if (visited.find(n)==visited.end()) {
                    q.push(n);
                    visited[n]=1;
                } else if (visited[n]==1) {
                    return false;
                }
            }
            visited[i]=2;
        }

        for (int i=0; i<n; i++) {
            if (visited.find(i)==visited.end()) {
                return false;
            }
        }

        return true;
    }
};

2. DFS

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        vector<int> visited(n, 0);        

        for (auto e:edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }        

        stack<int> stk;
        stk.push(0);
        visited[0]=1;
        
        while (!stk.empty()) {
            int t=stk.top();
            stk.pop();
            
            for (auto neighbor:graph[t]) {
                if (visited[neighbor]==0) {
                    stk.push(neighbor);
                    visited[neighbor]=1;
                } else if(visited[neighbor]==1) {
                    return false;
                }
            }
            visited[t]=2;
        }

        for (int i=0; i<n; i++) {
            if (visited[i]==0) return false;
        }

        return true;
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

