41. First Missing Positive
DescriptionHintsSubmissionsSolutions
Total Accepted: 97228
Total Submissions: 384102
Difficulty: Hard
Contributor: LeetCode
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

Subscribe to see which companies asked this question.

Hide Tags Array
Hide Similar Problems (E) Missing Number (M) Find the Duplicate Number (E) Find All Numbers Disappeared in an Array

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            while (nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        
        for (int i=0; i<n; ++i) {
            if (nums[i]!=i+1) return i+1;
        }
        
        return n+1;
    }
};

