1671. Minimum Number of Removals to Make Mountain Array
Hard

139

0

Add to List

Share
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

 

Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
Example 3:

Input: nums = [4,3,2,1,1,2,3,1]
Output: 4
Example 4:

Input: nums = [1,2,3,4,4,3,2,1]
Output: 1
 

Constraints:

3 <= nums.length <= 1000
1 <= nums[i] <= 109
It is guaranteed that you can make a mountain array out of nums.

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int res=INT_MIN, n=nums.size();
        vector<int> sorted, dp(n);
        for (int i=0; i<n; ++i) {
            auto it=lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if (it==sorted.end()) sorted.push_back(nums[i]);
            else *it=nums[i];
            dp[i]=sorted.size();
        }
        sorted.clear();
        for (int i=n-1; i>0; --i) {
            auto it=lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if (it==sorted.end()) sorted.push_back(nums[i]);
            else *it=nums[i];
            if (dp[i]>1 && sorted.size()>1) res=max(res, int(dp[i]+sorted.size()-1));
        }
        return n-res;
    }
};

