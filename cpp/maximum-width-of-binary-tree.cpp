662. Maximum Width of Binary Tree
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.

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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long res=0;
        vector<pair<unsigned long, unsigned long>> pos;
        dfs(root, pos, 0, 1);
        for (auto& p:pos) res=max(res, p.second-p.first+1);
        return res;
    }
private:
    void dfs(TreeNode* root, vector<pair<unsigned long, unsigned long>>& pos, int level, unsigned long curr) {
        if (root==NULL) return;
        if (level==pos.size()) pos.push_back({curr, curr});
        else {
            pos[level].first=min(pos[level].first, curr);
            pos[level].second=max(pos[level].second, curr);
        }
        dfs(root->left, pos, level+1, 2*curr);
        dfs(root->right, pos, level+1, 2*curr+1);
    }
};
