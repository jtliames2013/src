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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if (n==0) return res;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-2; i++) {
            if (i==0 || nums[i]!=nums[i-1]) {
                if (nums[i]+nums[i+1]+nums[i+2]>0) break;
                if (nums[i]+nums[n-2]+nums[n-1]<0) continue;
                int l=i+1, r=n-1;
                while (l<r) {
                    if (nums[i]+nums[l]+nums[r]==0) {
                        res.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l<r && nums[l]==nums[l-1]) l++;
                        while (l<r && nums[r]==nums[r+1]) r--;
                    } else if (nums[i]+nums[l]+nums[r]<0) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        
        return res;
    }
};

int main()
{
	return 0;
}


