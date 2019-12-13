1245. Tree Diameter
Medium

108

2

Favorite

Share
Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.

The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v.  Each node has labels in the set {0, 1, ..., edges.length}.

 

Example 1:



Input: edges = [[0,1],[0,2]]
Output: 2
Explanation: 
A longest path of the tree is the path 1 - 0 - 2.
Example 2:



Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: 
A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
 

Constraints:

0 <= edges.length < 10^4
edges[i][0] != edges[i][1]
0 <= edges[i][j] <= edges.length
The given edges form an undirected tree.

Google
|
LeetCode

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int res=0, n=edges.size();
        vector<unordered_set<int>> tree(n+1);
        for (auto& e:edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(res, 0, -1, tree);
        return res;
    }
private:
    int dfs(int& res, int root, int parent, vector<unordered_set<int>>& tree) {
        int depth=0, mx1=0, mx2=0;
        for (auto child:tree[root]) {
            if (child==parent) continue;
            int d=dfs(res, child, root, tree);
            if (mx1<d) {
                mx2=mx1;
                mx1=d;
            } else if (mx2<d) {
                mx2=d;
            }
        }
        res=max(res, mx1+mx2);
        return mx1+1;
    }
};

