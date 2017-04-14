213. House Robber II  
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Hide Company Tags Microsoft
Hide Tags Dynamic Programming
Hide Similar Problems (E) House Robber (M) Paint House (E) Paint Fence (M) House Robber III

class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int odd=0, even=0;
        for (int i=start; i<=end; i++) {
            if (i%2==0) {
                even=max(odd, even+nums[i]);
            } else {
                odd=max(even, odd+nums[i]);
            }
        }
        return max(odd, even);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        return max(robLinear(nums, 0, n-2), robLinear(nums, 1, n-1));
    }
};


