590. N-ary Tree Postorder Traversal
Easy

354

44

Favorite

Share
Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its postorder traversal as: [5,6,3,2,4,1].

 
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root==NULL) return res;
        stack<Node*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            Node* t=stk.top();
            stk.pop();
            res.push_back(t->val);
            for (auto c:t->children) stk.push(c);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
