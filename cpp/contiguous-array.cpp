525. Contiguous Array Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 7016
Total Submissions: 19227
Difficulty: Medium
Contributors:
bishwa
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

Subscribe to see which companies asked this question.

Hide Tags Hash Table
Hide Similar Problems (M) Maximum Size Subarray Sum Equals k

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0, n=nums.size(), zeros=0, ones=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for (int i=0; i<n; i++) {
            if (nums[i]==0) zeros++;
            else ones++;
            
            int diff=zeros-ones;
            if (mp.find(diff)!=mp.end()) {
                res=max(res, i-mp[diff]);
            } else {
                mp[diff]=i;
            }
        }
        return res;
    }
};

