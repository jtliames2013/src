1373. Maximum Sum BST in Binary Tree
Hard

34

2

Add to List

Share
Given a binary tree root, the task is to return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
Example 4:

Input: root = [2,1,3]
Output: 6
Example 5:

Input: root = [5,4,8,3,null,6,3]
Output: 7
 

Constraints:

Each tree has at most 40000 nodes..
Each node's value is between [-4 * 10^4 , 4 * 10^4].

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
    int maxSumBST(TreeNode* root) {
        if (root==NULL) return 0;
        maxSum=0;
        dfs(root);
        return maxSum;
    }
private:
    vector<int> dfs(TreeNode* root) {
        vector<int> res={1, root->val, root->val, root->val}; //isBST, lower, upper, sum
        if (root->left==NULL && root->right==NULL) {
            maxSum=max(maxSum, res[3]);
            return res;
        }
        if (root->left) {
            auto l=dfs(root->left);
            if (l[0]==0 || root->val<=l[2]) res[0]=0;
            res[1]=l[1];
            res[3]+=l[3];
        }
        if (root->right) {
            auto r=dfs(root->right);
            if (r[0]==0 || root->val>=r[1]) res[0]=0;
            res[2]=r[2];
            res[3]+=r[3];
        }
        if (res[0]) maxSum=max(maxSum, res[3]);
        return res;
    }
    int maxSum;
};

