988. Smallest String Starting From Leaf
Medium

193

40

Favorite

Share
Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)

 

Example 1:



Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:



Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:



Input: [2,2,1,null,1,0,null,0]
Output: "abc"
 

Note:

The number of nodes in the given tree will be between 1 and 8500.
Each node in the tree will have a value between 0 and 25.

Top down since string comparison should use the whole string, not the prefix

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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
private:
    string dfs(TreeNode* root, string parent) {
        if (root==NULL) return "";
        string res=string(1, root->val+'a')+parent;
        auto l=dfs(root->left, res);
        auto r=dfs(root->right, res); 
        if (l.empty() && r.empty()) return res;
        else if (l.empty()) return r;
        else if (r.empty()) return l;
        return (l+res)<(r+res)?l:r;
    }
};

