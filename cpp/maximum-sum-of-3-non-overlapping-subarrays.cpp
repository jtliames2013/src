689. Maximum Sum of 3 Non-Overlapping Subarrays
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> res(3);
        int n=nums.size();
        vector<vector<int>> dp(3, vector<int>(n));
        for (int i=0; i<3; i++) {
            int sum=0;            
            for (int j=i*k; j<n; j++) {
                sum+=nums[j];                
                if (j>=(i+1)*k-1) {
                    if (j>=(i+1)*k) sum-=nums[j-k];
                    dp[i][j]=max(j>0?dp[i][j-1]:0, (i>0?dp[i-1][j-k]:0)+sum);
                }
            }
        }
                
        for (int i=2; i>=0; i--) {
            for (int j=(i==2?n:res[i+1])-1; j>0; j--) {
                if (dp[i][j]!=dp[i][j-1]) {
                    res[i]=j-k+1;
                    break;
                }
            }
        }
        return res;
    }
};

