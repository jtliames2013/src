673. Number of Longest Increasing Subsequence
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        // first is length, second is number
        vector<pair<int,int>> dp(n, {1,1});
        int res=0, maxLen=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]>nums[j]) {
                    if (dp[i].first<dp[j].first+1) {
                        dp[i]={dp[j].first+1, dp[j].second};
                    } else if (dp[i].first==dp[j].first+1) {
                        dp[i].second+=dp[j].second;
                    }
                }
            }
            
            if (maxLen<dp[i].first) {
                maxLen=dp[i].first;
                res=dp[i].second;
            } else if (maxLen==dp[i].first) {
                res+=dp[i].second;
            }
        }
        return res;
    }
};
