663. Equal Tree Partition
Medium

258

20

Add to List

Share
Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000

Facebook
|
2

Amazon
|
LeetCode

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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> mp;
        int sum=dfs(root, mp);        
        if (sum==0) return mp[sum]>1;
        return sum%2==0 && mp.find(sum/2)!=mp.end();
    }
private:
    int dfs(TreeNode* root, unordered_map<int, int>& mp) {
        if (root==NULL) return 0;
        int curr=root->val+dfs(root->left, mp)+dfs(root->right, mp);
        mp[curr]++;
        return curr;
    }
};

