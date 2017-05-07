491. Increasing Subsequences Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 7118
Total Submissions: 18470
Difficulty: Medium
Contributors:
Stomach_ache
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
Subscribe to see which companies asked this question.

Hide Tags Depth-first Search

class Solution {
public:
    void findSubsequences(vector<vector<int>>& res, vector<int>& output, vector<int>& nums, int start) {
        if (output.size()>1) res.push_back(output);

        unordered_set<int> st;
        for (int i=start; i<nums.size(); i++) {
            if ((output.empty() || output.back()<=nums[i]) && st.find(nums[i])==st.end()) {
                output.push_back(nums[i]);
                st.insert(nums[i]);
                findSubsequences(res, output, nums, i+1);
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        findSubsequences(res, output, nums, 0);
        
        return res;
    }
};

