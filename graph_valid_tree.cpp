// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

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

