416. Partition Equal Subset Sum   QuestionEditorial Solution  My Submissions
Total Accepted: 5003 Total Submissions: 13472 Difficulty: Medium Contributors: Admin
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

Transition function: For each number, if we don't pick it, dp[i][j] = dp[i-1][j], which means if the first i-1 elements has made it to j, dp[i][j] would also make it to j (we can just ignore nums[i]). If we pick nums[i]. dp[i][j] = dp[i-1][j-nums[i]], which represents that j is composed of the current value nums[i] and the remaining composed of other previous numbers. Thus, the transition function is dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (auto n:nums) sum+=n;
        if ((sum & 0x1)==1) return false;
        sum/=2;
        vector<int> dp(sum+1,false);
        dp[0]=true;
        for (auto n:nums) {
            for (int i=sum; i>=n; i--) {
                dp[i]=dp[i]||dp[i-n];
            }
        }
        return dp[sum];
    }
};

