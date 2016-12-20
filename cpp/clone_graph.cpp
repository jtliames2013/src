133. Clone Graph 
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
Hide Company Tags Pocket Gems Google Uber Facebook
Hide Tags Depth-first Search Breadth-first Search Graph
Hide Similar Problems (H) Copy List with Random Pointer

NOTE: A node's neighbor could be the node itself, or have been visited. Therefore need a map to store mapping of original to clone.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

1. BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node==NULL) return NULL;
        queue<UndirectedGraphNode*> q;
        set<UndirectedGraphNode*> visited;
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        q.push(node);
        visited.insert(node);
        UndirectedGraphNode *cnode=new UndirectedGraphNode(node->label);
        m[node]=cnode;
        
        while(!q.empty()) {
            UndirectedGraphNode *f=q.front();
            q.pop();
            UndirectedGraphNode *parent=m[f];
            
            for (auto neighbor:f->neighbors) {
                if (visited.find(neighbor)==visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                    UndirectedGraphNode *n=new UndirectedGraphNode(neighbor->label);
                    m[neighbor]=n;
                }
				// must be out of if condition because a node can have itself as neighbor
                parent->neighbors.push_back(m[neighbor]);
            }
        }
        
        return cnode;
    }
};

2. DFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, set<UndirectedGraphNode*>& visited, map<UndirectedGraphNode*, UndirectedGraphNode*>& table) {
        visited.insert(node);
        UndirectedGraphNode *cnode=new UndirectedGraphNode(node->label);
        table[node]=cnode;
        
        for (auto neighbor:node->neighbors) {
            if (visited.find(neighbor)==visited.end()) {
                UndirectedGraphNode *cneighbor=cloneGraph(neighbor, visited, table);
                table[neighbor]=cneighbor;
            }
            cnode->neighbors.push_back(table[neighbor]);
        }
        
        return cnode;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node==NULL) return NULL;
        set<UndirectedGraphNode*> visited;
        map<UndirectedGraphNode*, UndirectedGraphNode*> table;
        return cloneGraph(node, visited, table);
    }
};

int main()
{
	return 0;
}

