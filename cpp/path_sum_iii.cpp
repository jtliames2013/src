437. Path Sum III   QuestionEditorial Solution  My Submissions
Total Accepted: 4579 Total Submissions: 12147 Difficulty: Easy Contributors: Stomach_ache
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
Subscribe to see which companies asked this question

Hide Tags Tree
Hide Similar Problems (E) Path Sum (M) Path Sum II

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
    int pathSum(TreeNode* root, unordered_map<int,int>& sums, int target, int currSum) {
        if (root==NULL) return 0;
        currSum+=root->val;
        int res=sums[currSum-target];
        sums[currSum]++;
        res+=pathSum(root->left, sums, target, currSum);
        res+=pathSum(root->right, sums, target, currSum);
        
        sums[currSum]--;
        return res;
    }
    
    int pathSum(TreeNode* root, int target) {
        unordered_map<int,int> sums;
        sums[0]=1;
        return pathSum(root, sums, target, 0);
    }
};

2. DFS
class Solution {
public:
    int pathSum(TreeNode* root, int target, int currSum) {
        if (!root) return 0;
        currSum+=root->val;
        return (currSum==target?1:0)+pathSum(root->left, target, currSum)+pathSum(root->right, target, currSum);
    }
    
    int pathSum(TreeNode* root, int target) {
        if (!root) return 0;
        return pathSum(root, target, 0)+pathSum(root->left, target)+pathSum(root->right, target);
    }
};

