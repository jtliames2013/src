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

class Solution {
public:
    bool dfs(vector<int>& nums, int start, int target) {
        if (target==0) return true;
        if (target<0) return false;
        for (int i=start; i<nums.size(); i++) {
            if (dfs(nums, i+1, target-nums[i])) return true;
        }
        return false;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (auto n:nums) sum+=n;
        if (sum%2==1) return false;
        return dfs(nums, 0, sum/2);
    }
};

2.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum/2;
        if (sum%2==1) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto num : nums) 
            for(int i=target; i>=num; i--)
                dp[i]=dp[i] || dp[i-num];
        return dp[target];
    }
};

https://chinmaylokesh.wordpress.com/2011/02/10/balanced-partition-problem-finding-the-minimized-sum-between-two-partitions-of-a-set-of-positive-integers/
