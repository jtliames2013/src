889. Construct Binary Tree from Preorder and Postorder Traversal
Medium

452

27

Favorite

Share
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        unordered_map<int,int> mp;
        for (int i=0; i<n; ++i) mp[post[i]]=i;
        return constructFromPrePost(pre, 0, n-1, post, 0, n-1, mp);
    }

private:
    TreeNode* constructFromPrePost(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd, unordered_map<int,int>& mp) {
        if (preStart>preEnd) return NULL;        
        TreeNode* n=new TreeNode(pre[preStart]);
        if (preStart==preEnd) return n;
        int index=mp[pre[preStart+1]];
        n->left=constructFromPrePost(pre, preStart+1, preStart+index-postStart+1, post, postStart, index, mp);
        n->right=constructFromPrePost(pre, preStart+index-postStart+2, preEnd, post, index+1, postEnd-1, mp);
        return n;
    }
};
