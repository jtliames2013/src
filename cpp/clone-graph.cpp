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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(node);
        visited.insert(node);
        Node* newNode=new Node(node->val);
        mp[node]=newNode;
        
        while (!q.empty()) {
            auto f=q.front();
            q.pop();
            
            for (auto neighbor:f->neighbors) {
                if (visited.find(neighbor)==visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                    Node* n=new Node(neighbor->val);
                    mp[neighbor]=n;
                }
                mp[f]->neighbors.push_back(mp[neighbor]);
            }
        }
        
        return newNode;
    }
};

2. DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        Node* n=new Node(node->val);
        mp[node]=n;
        for (auto neighbor:node->neighbors) {
            if (mp.find(neighbor)==mp.end()) {
                dfs(neighbor, mp);
            }
            n->neighbors.push_back(mp[neighbor]);
        }

        return n;
    }
};

