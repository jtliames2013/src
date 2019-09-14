53. Maximum Subarray Add to List
DescriptionSubmissionsSolutions
Total Accepted: 181174
Total Submissions: 462789
Difficulty: Easy
Contributor: LeetCode
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

Subscribe to see which companies asked this question.

Hide Tags Array Dynamic Programming Divide and Conquer
Hide Similar Problems (E) Best Time to Buy and Sell Stock (M) Maximum Product Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global=INT_MIN, local=0;
        for (auto n:nums) {
            local+=n;
            global=max(global, local);
            if (local<0) local=0;
        }
        return global;
    }
};
