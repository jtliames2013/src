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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	struct Node {
		unordered_set<int> neighbors;
		bool isLeaf() { return neighbors.size()==1; }
		bool isNonLeaf() { return neighbors.size() > 1; }
	};

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    	vector<int> res;
    	if (n==0) {
    		return res;
    	} else if (n==1) {
    		res.push_back(0);
    		return res;
    	} else if (n==2) {
    		res.push_back(0);
    		res.push_back(1);
    		return res;
    	} else {
			vector<Node> graph(n);
			vector<int> leaf;
			for (auto p:edges) {
				graph[p.first].neighbors.insert(p.second);
				graph[p.second].neighbors.insert(p.first);
			}

			while (1) {
				res.clear();
				leaf.clear();
				for (int i=0; i<graph.size(); i++) {
					if (graph[i].isNonLeaf()) res.push_back(i);
					if (graph[i].isLeaf()) leaf.push_back(i);
				}

				if (res.size()==1 || res.size()==2) return res;

				for (int i=0; i<leaf.size(); i++) {
					for (auto n:graph[leaf[i]].neighbors) {
						graph[n].neighbors.erase(leaf[i]);
					}
					graph[leaf[i]].neighbors.clear();
				}
			}
    	}
    }
};

int main()
{
	return 0;
}


