674. Longest Continuous Increasing Subsequence
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        int res=0, len=1;
        for (int i=1; i<n; i++) {
            if (nums[i]>nums[i-1]) len++;
            else {
                res=max(res, len);
                len=1;
            }
        }
        return max(res, len);
    }
};

