310. Minimum Height Trees 
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

Hint:

How many MHTs can a graph have at most?

解题思路：
参考LeetCode Discuss，链接地址：https://leetcode.com/discuss/71656/c-solution-o-n-time-o-n-space
基本思路是“逐层删去叶子节点，直到剩下根节点为止”
有点类似于拓扑排序
最终剩下的节点个数可能为1或者2
时间复杂度：O(n)，其中n为顶点的个数。

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n<=2) {
            for (int i=0; i<n; i++) res.push_back(i);
            return res;
        }
        
        vector<unordered_set<int>> graph(n);
        for (auto e:edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }

        for (int i=0; i<n; i++) {
            if (graph[i].size()==1) res.push_back(i);
        }
        
        while (n>2) {
            vector<int> next;
            for (int i=0; i<res.size(); i++) {
                for (auto v:graph[res[i]]) {
                    graph[v].erase(res[i]);
                    if (graph[v].size()==1) next.push_back(v);
                }
            }
            n-=res.size();
            res=next;
        }
        return res;
    }
};

