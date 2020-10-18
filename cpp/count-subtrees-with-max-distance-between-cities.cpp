1617. Count Subtrees With Max Distance Between Cities
Hard

95

19

Add to List

Share
There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.

A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.

For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.

Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.

Notice that the distance between the two cities is the number of edges in the path between them.

 

Example 1:



Input: n = 4, edges = [[1,2],[2,3],[2,4]]
Output: [3,4,0]
Explanation:
The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
No subtree has two nodes where the max distance between them is 3.
Example 2:

Input: n = 2, edges = [[1,2]]
Output: [1]
Example 3:

Input: n = 3, edges = [[1,2],[2,3]]
Output: [2,1]
 

Constraints:

2 <= n <= 15
edges.length == n-1
edges[i].length == 2
1 <= ui, vi <= n
All pairs (ui, vi) are distinct.

Bitmask + Floyd Warshall

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n-1);
        vector<vector<int>> dist(n, vector<int>(n, n));
        for (auto& e:edges) {
            dist[e[0]-1][e[1]-1]=dist[e[1]-1][e[0]-1]=1;
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        
        for (int i=0; i<(1<<n); ++i) {
            int d=maxDist(i, dist, n);
            if (d>0) res[d-1]++;
        }
        return res;
    }
private:
    int maxDist(int state, vector<vector<int>>& dist, int n) {
        int res=0, nodes=0, edges=0;
        for (int i=0; i<n; ++i) {
            if (((1<<i) & state)==0) continue;
            nodes++;
            for (int j=i+1; j<n; ++j) {
                if (((1<<j) & state)==0) continue;
                if (dist[i][j]==1) edges++;
                res=max(res, dist[i][j]);
            }
        }
        if (edges!=nodes-1) return 0;
        return res;
    }
};
