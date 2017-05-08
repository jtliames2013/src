523. Continuous Subarray Sum Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 8867
Total Submissions: 40921
Difficulty: Medium
Contributors:
xuehaohu
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming Math
Hide Similar Problems (M) Subarray Sum Equals K

We iterate through the input array exactly once, keeping track of the running sum mod k of the elements in the process. If we find that a running sum value at index j has been previously seen before in some earlier index i in the array, then we know that the sub-array (i,j] contains a desired sum.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        for (int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            if (k!=0) sum%=k;
            if (mp.find(sum)!=mp.end()) {
                if (i-mp[sum]>1) return true;
            }
            else {
                mp[sum]=i;
            }
        }
        return false;
    }
};

