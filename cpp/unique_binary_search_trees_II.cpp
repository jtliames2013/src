95. Unique Binary Search Trees II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 78249
Total Submissions: 252806
Difficulty: Medium
Contributor: LeetCode
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
Subscribe to see which companies asked this question.

Hide Tags Tree Dynamic Programming
Hide Similar Problems (M) Unique Binary Search Trees (M) Different Ways to Add Parentheses

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
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        if (start>end) {
            res.push_back(NULL);
            return res;
        }
        for (int i=start; i<=end; i++) {
            vector<TreeNode*> left=generateTrees(start, i-1);
            vector<TreeNode*> right=generateTrees(i+1, end);
            for (int j=0; j<left.size(); j++) {
                for (int k=0; k<right.size(); k++) {
                    TreeNode *n=new TreeNode(i);
                    n->left=left[j];
                    n->right=right[k];
                    res.push_back(n);
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
};

