747. Largest Number Greater Than Twice of Others
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
Note:
nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        if (n<2) return 0;
        int max1=INT_MIN, max2=INT_MIN, idx;
        for (int i=0; i<n; i++) {
            if (max1<=nums[i]) {
                max2=max1;
                max1=nums[i];
                idx=i;
            } else if (max2<=nums[i]) {
                max2=nums[i];
            }
        }
        return max1>=2*max2?idx:-1;
    }
};
