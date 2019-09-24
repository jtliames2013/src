508. Most Frequent Subtree Sum Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 10729
Total Submissions: 20650
Difficulty: Medium
Contributors:
Cyber233
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.

Subscribe to see which companies asked this question.

Hide Tags Tree Hash Table
Hide Similar Problems (E) Subtree of Another Tree

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int,int> mp;
        int maxCount=0;
        dfs(root, mp, maxCount);
        for (auto iter:mp) {
            if (iter.second==maxCount) res.push_back(iter.first);
        }
        return res;
    }
private:
    int dfs(TreeNode* root, unordered_map<int,int>& mp, int& maxCount) {
        if (root==NULL) return 0;
        auto l=dfs(root->left, mp, maxCount);
        auto r=dfs(root->right, mp, maxCount);
        int sum=root->val+l+r;
        mp[sum]++;
        maxCount=max(maxCount, mp[sum]);

        return sum;
    }
};
