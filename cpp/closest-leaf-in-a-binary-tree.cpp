742. Closest Leaf in a Binary Tree
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a binary tree where every node has a unique value, and a target key k, find the value of the closest leaf node to target k in the tree.

Here, closest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the closest leaf node to the target of 1.
Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The closest leaf node is the root node itself.
Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is closest to the node with value 2.
Note:
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000].
There exists some node in the given binary tree for which node.val == k.

Databricks
|
3

Google
|
4

Amazon
|
2

Facebook
|
2

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> edges;
        TreeNode* target=dfs(root, k, edges);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        
        while (!q.empty()) {
            auto f=q.front();
            q.pop();
            if (f->left==NULL && f->right==NULL) return f->val;
            
            vector<TreeNode*> v;
            if (f->left && visited.find(f->left)==visited.end()) v.push_back(f->left);
            if (f->right && visited.find(f->right)==visited.end()) v.push_back(f->right);
            if (edges.find(f)!=edges.end() && visited.find(edges[f])==visited.end()) v.push_back(edges[f]);
            
            for (auto& n:v) {
                q.push(n);
                visited.insert(n);
            }
        }
        return 0;
    }
private:
    TreeNode* dfs(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& edges) {
        if (root==NULL) return NULL;
        if (root->val==k) return root;
        TreeNode* l=dfs(root->left, k, edges);
        if (l) {
            edges[root->left]=root;
            return l;
        }
        TreeNode* r=dfs(root->right, k, edges);
        if (r) {
            edges[root->right]=root;
            return r;
        }
        return NULL;
    }
};

