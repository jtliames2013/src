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

1. use two queues

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (node == NULL) return NULL;
    	queue<UndirectedGraphNode *> q, cloneq;
    	map<int, UndirectedGraphNode *> m;

    	UndirectedGraphNode *clonenode = new UndirectedGraphNode(node->label);
    	q.push(node);
    	cloneq.push(clonenode);
    	m.insert({node->label, clonenode});
    	while (!q.empty())
    	{
    		UndirectedGraphNode *n = q.front();
    		q.pop();
    		UndirectedGraphNode *clonen = cloneq.front();
    		cloneq.pop();

    		for (int i = 0; i < n->neighbors.size(); i++)
    		{
    			UndirectedGraphNode *cloneneighbor;
    			if (m.find(n->neighbors[i]->label) == m.end())
    			{
        			cloneneighbor = new UndirectedGraphNode(n->neighbors[i]->label);
    				q.push(n->neighbors[i]);
        			m.insert({n->neighbors[i]->label, cloneneighbor});
        			cloneq.push(cloneneighbor);
        			m.insert({cloneneighbor->label, cloneneighbor});
    			}
    			else if (n == n->neighbors[i])
    			{
    				cloneneighbor = clonen;
    			}
    			else
    			{
    				auto res = m.find(n->neighbors[i]->label);
    				cloneneighbor = res->second;
    			}
    			clonen->neighbors.push_back(cloneneighbor);
    		}
    	}

    	return clonenode;
    }
};

2. use one queue
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_set<UndirectedGraphNode*> visited;
        queue<pair<UndirectedGraphNode*, UndirectedGraphNode*>> q;
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        if (node==NULL)  return NULL;       

        UndirectedGraphNode *cnode=new UndirectedGraphNode(node->label);
        q.push(make_pair(node, cnode));
        m[node]=cnode;
        visited.insert(node);
        
        while(!q.empty()) {
            auto t=q.front();
            q.pop();            

            for (auto neighbor:t.first->neighbors) {
                if (visited.find(neighbor)==visited.end()) {
                    UndirectedGraphNode *cn=new UndirectedGraphNode(neighbor->label);
                    t.second->neighbors.push_back(cn);                    
                    q.push(make_pair(neighbor, cn));
                    m[neighbor]=cn;
                    visited.insert(neighbor);
                } else {
                    t.second->neighbors.push_back(m[neighbor]);   
                }
            }
        }
        
        return cnode;
    }
};

3. Don't use pair in queue since map has the info.
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

int main()
{
	return 0;
}

