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

1. BFS
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node==NULL) return NULL;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
        queue<UndirectedGraphNode*> q;
        unordered_set<UndirectedGraphNode*> visited;
        q.push(node);
        visited.insert(node);
        UndirectedGraphNode* newNode=new UndirectedGraphNode(node->label);
        mp[node]=newNode;
        
        while (!q.empty()) {
            UndirectedGraphNode* f=q.front();
            q.pop();
            UndirectedGraphNode* p=mp[f];
            
            for (auto neighbor:f->neighbors) {
                if (visited.find(neighbor)==visited.end()) {
                    UndirectedGraphNode* n=new UndirectedGraphNode(neighbor->label);
                    mp[neighbor]=n;
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
                p->neighbors.push_back(mp[neighbor]);
            }
        }
        
        return newNode;
    }
};

2. DFS
class Solution {
public:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& mp, unordered_set<UndirectedGraphNode*>& visited) {
        UndirectedGraphNode *newNode=new UndirectedGraphNode(node->label);
        mp[node]=newNode;
        visited.insert(node);
        for (auto neighbor:node->neighbors) {
            if (visited.find(neighbor)==visited.end()) {
                mp[neighbor]=dfs(neighbor, mp, visited);
            }
            newNode->neighbors.push_back(mp[neighbor]);
        }
        
        return newNode;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node==NULL) return NULL;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
        unordered_set<UndirectedGraphNode*> visited;
        return dfs(node, mp, visited);
    }
};

