589. N-ary Tree Preorder Traversal
Easy

286

40

Favorite

Share
Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its preorder traversal as: [1,3,5,6,2,4].

 

Note:

Recursive solution is trivial, could you do it iteratively?

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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root==NULL) return res;
        stack<Node*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            Node* t=stk.top();
            stk.pop();
            res.push_back(t->val);
            for (auto iter=t->children.rbegin(); iter!=t->children.rend(); iter++) stk.push(*iter);
        }
        
        return res;
    }
};
