559. Maximum Depth of N-ary Tree
Easy

435

23

Favorite

Share
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example, given a 3-ary tree:

 


 

We should return its max depth, which is 3.

 

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.

1. DFS
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root==NULL) return 0;
        int depth=0;
        for (auto c:root->children) depth=max(depth, maxDepth(c));
        return depth+1;
     }
};

2. BFS
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root==NULL) return 0;        
        queue<Node*> q;
        q.push(root);
        int depth=0;
        
        while (!q.empty()) {
            int n=q.size();
            for (int i=0; i<n; ++i) {
                Node* f=q.front();
                q.pop();
                for (auto c:f->children) q.push(c);
            }
            depth++;
        }
        
        return depth;
     }
};
