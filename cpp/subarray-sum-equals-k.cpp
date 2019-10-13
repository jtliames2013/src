560. Subarray Sum Equals K Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 4138
Total Submissions: 9370
Difficulty: Medium
Contributors:
love_Fawn
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
Subscribe to see which companies asked this question.

Hide Tags Array Map
Hide Similar Problems (E) Two Sum (M) Continuous Subarray Sum

ass Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0, sum=0;
        unordered_map<int,int> mp;
        mp[sum]=1;
        for (auto& n:nums) {
            sum+=n;
            if (mp.find(sum-k)!=mp.end()) res+=mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};
