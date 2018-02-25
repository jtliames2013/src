15. 3Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 134780 Total Submissions: 685476 Difficulty: Medium
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if (n==0) return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1, r=n-1;
            if (nums[i]+nums[l]+nums[l+1]>0) break;
            if (nums[i]+nums[r-1]+nums[r]<0) continue;

            while (l<r) {
                int sum=nums[i]+nums[l]+nums[r];
                if (sum==0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l<r && nums[l]==nums[l-1]) l++;
                    r--;
                    while (l<r && nums[r]==nums[r+1]) r--;
                } else if (sum<0) {
                    l++;
                } else {
                    r--;
                }
            }            
        }

        return res;
    }
};

