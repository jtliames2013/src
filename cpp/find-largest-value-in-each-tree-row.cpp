515. Find Largest Value in Each Tree Row Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 12594
Total Submissions: 23314
Difficulty: Medium
Contributors:
love_Fawn
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search Breadth-first Search

1. BFS
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int largest=INT_MIN, size=q.size();
            for (int i=0; i<size; i++) {
                TreeNode* f=q.front();
                q.pop();
                largest=max(largest, f->val);
                
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            res.push_back(largest);
        }
        
        return res;
    }
};

2. DFS
class Solution {
public:
    void dfs(vector<int>& res, TreeNode* root, int depth) {
        if (root==NULL) return;
        
        if (res.size()<depth) {
            res.push_back(root->val);
        } else {
            res[depth-1]=max(res[depth-1], root->val);
        }
        
        if (root->left) dfs(res, root->left, depth+1);
        if (root->right) dfs(res, root->right, depth+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;

        dfs(res, root, 1);
        return res;
    }
};

