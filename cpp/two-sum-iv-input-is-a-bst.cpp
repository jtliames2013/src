653. Two Sum IV - Input is a BST
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
1. DFS
class Solution {
public:
    bool dfs(unordered_set<int>& st, TreeNode* root, int k) {
        if (root==NULL) return false;
        if (st.find(k-root->val)!=st.end()) return true;
        st.insert(root->val);
        return dfs(st, root->left, k) || dfs(st, root->right, k);        
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return dfs(st, root, k);
    }
};

2. Two pointer
class Solution {
public:
    void dfs(vector<int>& v, TreeNode* root) {
        if (root==NULL) return;
        dfs(v, root->left);
        v.push_back(root->val);
        dfs(v, root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        dfs(nums, root);
        int l=0, r=nums.size()-1;
        while (l<r) {
            if (nums[l]+nums[r]==k) return true;
            else if (nums[l]+nums[r]<k) l++;
            else r--;
        }
        return false;
    }
};


