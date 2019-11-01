847. Shortest Path Visiting All Nodes
DescriptionHintsSubmissionsDiscussSolution
An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
 

Note:

1 <= graph.length <= 12
0 <= graph[i].length < graph.length

struct Path {
    int visited;
    int curr;
    int length;
    Path(int v,  int c, int l):visited(v), curr(c), length(l) {}
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<Path> q;
        set<pair<int,int>> st;
        for (int i=0; i<n; ++i) {
            q.push(Path(1<<i, i, 0));
            st.insert({1<<i, i});
        }
        
        while (!q.empty()) {
            auto f=q.front();
            q.pop();
            if (f.visited==(1<<n)-1) return f.length;
            
            for (auto neighbor:graph[f.curr]) {
                int v=(1<<neighbor)|f.visited;
                if (st.find({v, neighbor})==st.end()) {
                    q.push(Path(v, neighbor, f.length+1));
                    st.insert({v, neighbor});
                }
            }
        }
        return -1;
    }
};
