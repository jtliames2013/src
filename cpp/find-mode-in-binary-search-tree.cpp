501. Find Mode in Binary Search Tree Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 12533
Total Submissions: 32628
Difficulty: Easy
Contributors:
Coder_1215
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

Subscribe to see which companies asked this question.

Hide Tags Tree
Hide Similar Problems (M) Validate Binary Search Tree

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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        prev=LONG_MIN;
        count=0;
        maxCount=INT_MIN;

        dfs(res, root);
        return res;
    }
private:
    void dfs(vector<int>& res, TreeNode* root) {
        if (root==NULL) return;
        dfs(res, root->left);
        if (root->val!=prev) {
            count=0;
            prev=root->val;
        }
        count++;
        
        if (count>maxCount) {
            maxCount=count;
            res.clear();
            res.push_back(prev);
        } else if (count==maxCount) {
            res.push_back(prev);
        }
        
        dfs(res, root->right);
    }
    
    long prev;
    int count;
    int maxCount;
};
