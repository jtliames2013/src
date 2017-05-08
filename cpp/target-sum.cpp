494. Target Sum Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 16571
Total Submissions: 37841
Difficulty: Medium
Contributors:
kevin.xinzhao@gmail.com
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
Subscribe to see which companies asked this question.

Hide Tags Depth-first Search Dynamic Programming
Hide Similar Problems (H) Expression Add Operators

1. DFS with optimization
class Solution {
public:
    int dfs(vector<int>& nums, unordered_map<string,int>& mp, int S, int start, vector<int>& sums) {
        if (start==nums.size()) return S==0?1:0;
        if (sums[start]<abs(S)) return 0;
        string key=to_string(S)+','+to_string(start);
        if (mp.find(key)!=mp.end()) return mp[key];
        
        int res=0;
        res+=dfs(nums, mp, S-nums[start], start+1, sums);
        res+=dfs(nums, mp, S+nums[start], start+1, sums);
        mp[key]=res;
        
        return res;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> sums(n);
        sums[n-1]=nums[n-1];
        for (int i=n-2; i>=0; i--) sums[i]=nums[i]+sums[i+1];
        unordered_map<string,int> mp;
        
        return dfs(nums, mp, S, 0, sums);
    }
};

2. DP
The recursive solution is very slow, because its runtime is exponential

The original problem statement is equivalent to:
Find a subset of nums that need to be positive, and the rest of them negative, such that the sum is equal to target

Let P be the positive subset and N be the negative subset
For example:
Given nums = [1, 2, 3, 4, 5] and target = 3 then one possible solution is +1-2+3-4+5 = 3
Here positive subset is P = [1, 3, 5] and negative subset is N = [2, 4]

Then let's see how this can be converted to a subset sum problem:

                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
So the original problem has been converted to a subset sum problem as follows:
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2

Note that the above formula has proved that target + sum(nums) must be even

We can use that fact to quickly identify inputs that do not have a solution (Thanks to @BrunoDeNadaiSarnaglia for the suggestion)
For detailed explanation on how to solve subset sum problem, you may refer to Partition Equal Subset Sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for (auto n:nums) sum+=n;
        if (sum<abs(S) || (sum+S)%2!=0) return 0;
        
        int target=(sum+S)/2;
        vector<int> dp(target+1);
        dp[0]=1;
        for (auto n:nums) {
            // update from previous iteration. this is different from combination sum iv
            for (int i=target; i>=n; i--) {
                dp[i]+=dp[i-n];
            } 
        }
        return dp[target];
    }
};

