1712. Ways to Split Array Into Three Subarrays
Medium

122

22

Add to List

Share
A split of an integer array is good if:

The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,1,1]
Output: 1
Explanation: The only good way to split nums is [1] [1] [1].
Example 2:

Input: nums = [1,2,2,2,5,0]
Output: 3
Explanation: There are three good ways of splitting nums:
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
Example 3:

Input: nums = [3,2,1]
Output: 0
Explanation: There is no good way to split nums.
 

Constraints:

3 <= nums.length <= 105
0 <= nums[i] <= 104

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int res=0, n=nums.size();
        for (int i=1; i<n; ++i) nums[i]+=nums[i-1];
        
        for (int i=0; i<n-2; ++i) {
            auto lower=lower_bound(nums.begin()+i+1, nums.end(), nums[i]*2);
            if (lower!=nums.end()) {
                auto upper=upper_bound(lower, prev(nums.end()), (nums[i]+nums.back())/2);
                if (upper!=lower) {
                    res=(res+(upper-lower))%mod;
                }
            }
        }
        return res;
    }
private:
    const int mod=1e9+7;
};

