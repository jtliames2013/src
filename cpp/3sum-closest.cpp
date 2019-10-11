16. 3Sum Closest  QuestionEditorial Solution  My Submissions
Total Accepted: 88362 Total Submissions: 296331 Difficulty: Medium
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Hide Company Tags Bloomberg
Hide Tags Array Two Pointers
Hide Similar Problems (M) 3Sum (M) 3Sum Smaller

ass Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size(), res, diff=INT_MAX;
        if (n==0) return 0;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-2; ++i) {
            int l=i+1, r=n-1, sum;
            while (l<r) {
                sum=nums[i]+nums[l]+nums[r];
                if (diff>abs(sum-target)) {
                    diff=abs(sum-target);
                    res=sum;
                }
                if (sum==target) return res;
                else if (sum>target) r--;
                else l++;
            }
        }
        return res;
    }
};
