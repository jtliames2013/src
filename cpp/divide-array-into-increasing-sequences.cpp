1121. Divide Array Into Increasing Sequences
Hard

40

15

Add to List

Share
Given a non-decreasing array of positive integers nums and an integer K, find out if this array can be divided into one or more disjoint increasing subsequences of length at least K.

 

Example 1:

Input: nums = [1,2,2,3,3,4,4], K = 3
Output: true
Explanation: 
The array can be divided into the two subsequences [1,2,3,4] and [2,3,4] with lengths at least 3 each.
Example 2:

Input: nums = [5,6,6,7,8], K = 3
Output: false
Explanation: 
There is no way to divide the array using the conditions required.
 

Note:

1 <= nums.length <= 10^5
1 <= K <= nums.length
1 <= nums[i] <= 10^5

Google
|
LeetCode

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int count=0, mx=0, n=nums.size();
        for (int i=1; i<n; ++i) {
            if (nums[i]==nums[i-1]) count++;
            else count=1;
            mx=max(mx, count);
        }
        return n>=K*mx;
    }    
};

