1063. Number of Valid Subarrays
Hard

54

8

Add to List

Share
Given an array A of integers, return the number of non-empty continuous subarrays that satisfy the following condition:

The leftmost element of the subarray is not larger than other elements in the subarray.

 

Example 1:

Input: [1,4,2,5,3]
Output: 11
Explanation: There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],[2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].
Example 2:

Input: [3,2,1]
Output: 3
Explanation: The 3 valid subarrays are: [3],[2],[1].
Example 3:

Input: [2,2,2]
Output: 6
Explanation: There are 6 valid subarrays: [2],[2],[2],[2,2],[2,2],[2,2,2].
 

Note:

1 <= A.length <= 50000
0 <= A[i] <= 100000

Hulu
|
LeetCode

class Solution {
public:
    int validSubarrays(vector<int>& nums) {        
        nums.push_back(-1);
        int res=0, n=nums.size();
        vector<int> stk;
        for (int i=0; i<n; ++i) {
            while (!stk.empty() && nums[i]<nums[stk.back()]) {
                res+=i-stk.back();
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return res;
    }
};


