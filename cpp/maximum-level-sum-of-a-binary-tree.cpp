1161. Maximum Level Sum of a Binary Tree
Medium

21

0

Favorite

Share
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 

Example 1:



Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
 

Note:

The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5

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
    int maxLevelSum(TreeNode* root) {
        int maxLevel=0, maxSum=0, level=0;
        if (!root) return maxLevel;
        queue<TreeNode*> q;
        q.push(root);
        level++;
        
        while (!q.empty()) {
            int n=q.size();
            int sum=0;
            for (int i=0; i<n; ++i) {
                TreeNode* f=q.front();
                sum+=f->val;
                q.pop();
                
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            if (sum>maxSum) {
                maxSum=sum;
                maxLevel=level;
            }
            level++;
        }
        
        return maxLevel;
    }
};

2. DFS
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        dfs(root, sum, 0);
        
        int maxSum=sum[0], maxLevel=0;
        for (int i=1; i<sum.size(); ++i) {
            if (sum[i]>maxSum) {
                maxSum=sum[i];
                maxLevel=i;
            }
        }
        return maxLevel+1;
    }

private:
    void dfs(TreeNode* root, vector<int>& sum, int level) {
        if (!root) return;
        level++;
        if (sum.size()<level) sum.resize(level);
        sum[level-1]+=root->val;
        dfs(root->left, sum, level);
        dfs(root->right, sum, level);        
    }
};

