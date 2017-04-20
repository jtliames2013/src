152. Maximum Product Subarray Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 94259
Total Submissions: 376079
Difficulty: Medium
Contributor: LeetCode
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question.

Hide Tags Array Dynamic Programming
Hide Similar Problems (E) Maximum Subarray (E) House Robber (M) Product of Array Except Self

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        int maxLocal=nums[0], minLocal=nums[0], global=nums[0];
        
        for (int i=1; i<n; i++) {
            int tmp=maxLocal;
            maxLocal=max(max(minLocal*nums[i], maxLocal*nums[i]), nums[i]);
            minLocal=min(min(minLocal*nums[i], tmp*nums[i]), nums[i]);
            global=max(global, maxLocal);
        }
        return global;
    }
};

