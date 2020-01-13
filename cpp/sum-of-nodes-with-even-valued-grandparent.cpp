1315. Sum of Nodes with Even-Valued Grandparent
Medium

47

4

Add to List

Share
Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.

 

Example 1:



Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.

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
    int sumEvenGrandparent(TreeNode* root) {
        sum=0;
        dfs(root, NULL, NULL);
        return sum;
    }
private:
    void dfs(TreeNode* root, TreeNode* parent, TreeNode* grandparent) {
        if (root==NULL) return;
        if (grandparent!=NULL && grandparent->val%2==0) sum+=root->val;
        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }
    
    int sum;
};

