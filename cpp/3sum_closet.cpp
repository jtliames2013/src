16. 3Sum Closest  QuestionEditorial Solution  My Submissions
Total Accepted: 88362 Total Submissions: 296331 Difficulty: Medium
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Hide Company Tags Bloomberg
Hide Tags Array Two Pointers
Hide Similar Problems (M) 3Sum (M) 3Sum Smaller

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
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if (n==0) return 0;
        int mingap=INT_MAX;
        int res;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            while (l<r) {
                int sum=nums[i]+nums[l]+nums[r];
                int gap=abs(sum-target);
                if (mingap>gap) {
                    mingap=gap;
                    res=sum;
                }
                if (sum==target) return sum;
                else if (sum<target) l++;
                else r--;
            }
        }
        return res;
    }
};

int main()
{
	return 0;
}


