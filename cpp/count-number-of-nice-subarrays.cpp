1248. Count Number of Nice Subarrays
Medium

131

4

Favorite

Share
Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k)-atMost(nums, k-1);
    }
private:
    int atMost(vector<int>& nums, int k) {
        int res=0;
        for (int l=0, r=0; r<nums.size(); ++r) {
            k-=nums[r]%2;
            while (k<0) {
                k+=nums[l++]%2;
            }
            res+=r-l+1;
        }
        return res;
    }
};
