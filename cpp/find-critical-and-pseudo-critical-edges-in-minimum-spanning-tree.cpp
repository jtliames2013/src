1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
Hard

37

18

Add to List

Share
Given a weighted undirected connected graph with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between nodes fromi and toi. A minimum spanning tree (MST) is a subset of the edges of the graph that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the minimum spanning tree (MST) of the given graph. An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. A pseudo-critical edge, on the other hand, is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

 

Example 1:



Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
Example 2:



Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
 

Constraints:

2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti <= 1000
All pairs (fromi, toi) are distinct.

minimum spanning tree
Kruskal's algorithm

Use the Kruskal algorithm to find the minimum spanning tree by sorting the edges and picking edges from ones with smaller weights.
Use a disjoint set to avoid adding redundant edges that result in a cycle.
To find if one edge is critical, delete that edge and re-run the MST algorithm and see if the weight of the new MST increases.
To find if one edge is non-critical (in any MST), include that edge to the accepted edge list and continue the MST algorithm, then see if the resulting MST has the same weight of the initial MST of the entire graph.

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(2);
        for (int i=0; i<edges.size(); ++i) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){ return a[2]<b[2]; });
        int mn=getWeight(n, edges, -1, -1);
        for (int i=0; i<edges.size(); ++i) {
            if (mn<getWeight(n, edges, i, -1)) res[0].push_back(edges[i][3]);
            else if (mn==getWeight(n, edges, -1, i)) res[1].push_back(edges[i][3]);
        }

        return res;
    }
private:
    int getWeight(int n, vector<vector<int>>& edges, int exclude, int include) {
        int weight=0, count=n;
        vector<int> root(n);
        for (int i=0; i<n; ++i) root[i]=i;
        if (include!=-1) {
            int p1=find(root, edges[include][0]);
            int p2=find(root, edges[include][1]);
            root[p1]=p2;
            count--;
            weight+=edges[include][2];
        }

        for (int i=0; i<edges.size(); ++i) {
            if (i==exclude || i==include) continue;
            int p1=find(root, edges[i][0]);
            int p2=find(root, edges[i][1]);
            if (p1!=p2) {
                root[p1]=p2;
                count--;
                weight+=edges[i][2];
            }
        }

        return count==1?weight:INT_MAX;
    }

    int find(vector<int>& root, int i) {
        while (root[i]!=i) i=root[i];
        return i;
    }
};


