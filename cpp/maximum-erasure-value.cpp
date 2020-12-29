1695. Maximum Erasure Value
Medium

137

5

Add to List

Share
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res=0, sum=0, n=nums.size(), l=0, r=0;
        unordered_set<int> st;
        for (; r<n; ++r) {
            while (st.find(nums[r])!=st.end()) {
                sum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            sum+=nums[r];
            st.insert(nums[r]);
            res=max(res, sum);
        }
        
        return res;
    }
};

