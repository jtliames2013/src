863. All Nodes Distance K in Binary Tree
DescriptionHintsSubmissionsDiscussSolution
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        unordered_map<int, set<int>> graph;
        build(root, NULL, graph);
        queue<int> q;
        unordered_set<int> visited;        
        q.push(target->val);
        visited.insert(target->val);

        while (!q.empty()) {
            if (K<0) break;
            int n=q.size();
            for (int i=0; i<n; ++i) {
                int f=q.front();
                q.pop();
                if (K==0) res.push_back(f);

                for (auto neighbor:graph[f])  {
                    if (visited.find(neighbor)==visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            K--;
        }
        
        return res;
    }
private:
    void build(TreeNode* node, TreeNode* parent, unordered_map<int, set<int>>& graph) {
        if (!node) return;
        if (parent) {
            graph[parent->val].insert(node->val);
            graph[node->val].insert(parent->val);
        }
        build(node->left, node, graph);
        build(node->right, node, graph);
    }
};

2.
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        unordered_map<int, set<int>> graph;
        build(root, NULL, graph);
        queue<int> q;
        unordered_set<int> visited;
        q.push(target->val);
        visited.insert(target->val);
        if (K==0) res.push_back(target->val);

        while (!q.empty()) {
            if (K==0) break;
            int n=q.size();
            for (int i=0; i<n; ++i) {
                int f=q.front();
                q.pop();

                for (auto neighbor:graph[f])  {
                    if (visited.find(neighbor)==visited.end()) {
                        if (K==1) res.push_back(neighbor);
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            K--;
        }

        return res;
    }
private:
    void build(TreeNode* node, TreeNode* parent, unordered_map<int, set<int>>& graph) {
        if (!node) return;
        if (parent) {
            graph[parent->val].insert(node->val);
            graph[node->val].insert(parent->val);
        }
        build(node->left, node, graph);
        build(node->right, node, graph);
    }
};

