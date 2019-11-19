968. Binary Tree Cameras
Hard

428

11

Favorite

Share
Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Note:

The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.

Consider a node in the tree.
It can be covered by its parent, itself, its two children.
Four options.

Consider the root of the tree.
It can be covered by left child, or right child, or itself.
Three options.

Consider one leaf of the tree.
It can be covered by its parent or by itself.
Two options.

If we set a camera at the leaf, the camera can cover the leaf and its parent.
If we set a camera at its parent, the camera can cover the leaf, its parent and its sibling.

We can see that the second plan is always better than the first.
Now we have only one option, set up camera to all leaves' parent.

Here is our greedy solution:

Set cameras on all leaves' parents, thenremove all covered nodes.
Repeat step 1 until all nodes are covered.

Explanation:
Apply a recusion function dfs.
Return 0 if it's a leaf.
Return 1 if it's a parent of a leaf, with a camera on this node.
Return 2 if it's coverd, without a camera on this node.

For each node,
if it has a child, which is leaf (node 0), then it needs camera.
if it has a child, which is the parent of a leaf (node 1), then it's covered.

If it needs camera, then res++ and we return 1.
If it's covered, we return 2.
Otherwise, we return 0.

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
    int minCameraCover(TreeNode* root) {
        int res=0;
        // 0 leaf, 1 camera, 2 covered
        return res+(dfs(res, root)<1?1:0);
    }
private:
    int dfs(int& res, TreeNode* root) {
        if (root==NULL) return 2;
        if (root->left==NULL && root->right==NULL) return 0;
        int l=dfs(res, root->left), r=dfs(res, root->right);
        if (l==0 || r==0) {
            res++;
            return 1;
        } else if (l==1 || r==1) {
            return 2;
        } else {
            return 0;
        }
    }
};

