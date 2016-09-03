368. Largest Divisible Subset 
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
Credits:
Special thanks to @Stomach_ache for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Dynamic Programming Math

思路：其实和求最大上升子序列LIS差不多，只不过这题要求输出序列而已。

先把数组排好序。首先要明确，若a<b且b%a==0 ,  b <c 且 c%b==0那么必然有c%a==0

我们设dp[i] 为最大的子集长度，更新的时候保存上一个的下标即可。

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        if (n==0) return res;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), index(n, -1);
        int maxdp=0, maxidx=-1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]%nums[j]==0 && dp[j]+1>dp[i]) {
                    dp[i]=dp[j]+1;
                    index[i]=j;
                }
            }
            if (maxdp<dp[i]) {
                maxdp=dp[i];
                maxidx=i;
            }
        }
        
        for (int i=maxidx; i!=-1; i=index[i]) {
            res.insert(res.begin(), nums[i]);
        }
        
        return res;
    }
};

