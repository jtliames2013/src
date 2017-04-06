108. Convert Sorted Array to Binary Search Tree  QuestionEditorial Solution  My Submissions
Total Accepted: 83034 Total Submissions: 216537 Difficulty: Medium
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Hide Company Tags Airbnb
Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Convert Sorted List to Binary Search Tree

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
    TreeNode* convert(vector<int>& nums, int start, int end) {
        if (start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* n=new TreeNode(nums[mid]);
        n->left=convert(nums, start, mid-1);
        n->right=convert(nums, mid+1, end);
        return n;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size()-1);
    }
};

