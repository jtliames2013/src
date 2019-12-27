325. Maximum Size Subarray Sum Equals k
 Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:

Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:

Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time? 

Solution
Subarray sum also known as Range sum can be defined as the sum of all elements in the range [i, j) where i < j denoted by S(i, j). Note that in this definition, i is inclusive and j is exclusive.

When i = 0, we often call it prefix sum, denoted by S[j] = S(0, j). It is easy to see that

S(i, j) = S[j] – S[i] and 0<= i < n and 0 < j <= n

Therefore if we have all the prefix sums calculated in O(n) any query of S(i, j) is O(1).

This is exactly what we did in the problem Range sum query – Immutable

OK, now let’s consider this problem. Suppose we calculated all the prefix sums and stored it in an array sums then the problem becomes:

maximize j - i
subject to sums[j] - sums[i] = k
This is only a variant of the famous problem two sum. The solution is almost the same

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum=0, res=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for (int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            if (mp.find(sum-k)!=mp.end()) res=max(res, i-mp[sum-k]);
            if (mp.find(sum)==mp.end()) mp[sum]=i;
        }
        
        return res;
    }
};

