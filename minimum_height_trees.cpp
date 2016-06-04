
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


