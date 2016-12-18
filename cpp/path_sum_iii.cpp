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
    void getSum(TreeNode* root, int sum, vector<int>& sums, int& num) {
        if (root==NULL) return;
        for (int i=0; i<sums.size(); i++) {
            if (sums[i]+root->val==sum) num++;
            sums[i]+=root->val;
        }
        sums.push_back(0);
        if (root->left) getSum(root->left, sum, sums, num);
        if (root->right) getSum(root->right, sum, sums, num);
        for (int i=0; i<(int)sums.size()-1; i++) sums[i]-=root->val;
        sums.pop_back();
    }
    int pathSum(TreeNode* root, int sum) {
        vector<int> sums={0};
        int num=0;
        getSum(root, sum, sums, num);
        return num;
    }
};

2.
class Solution {
public:
    int pathSum(TreeNode* root, int prev, int sum) {
        if (root==NULL) return 0;
        int curr=prev+root->val;
        return (curr==sum)+pathSum(root->left, curr, sum)+pathSum(root->right, curr, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root==NULL) return 0;
        return pathSum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};


