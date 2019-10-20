34. Find First and Last Position of Element in Sorted Array
Medium

2112

99

Favorite

Share
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

1.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        auto lower=lower_bound(nums.begin(), nums.end(), target);
        if (lower==nums.end() || *lower!=target) return res;
        res[0]=distance(nums.begin(), lower);
        auto upper=upper_bound(lower, nums.end(), target);
        res[1]=distance(nums.begin(), prev(upper));
        return res;
    }
};


2.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        int n=nums.size();
        if (n==0) return res;
        int l=0, r=n-1, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            if (nums[mid]<target) l=mid+1;
            else r=mid;
        }
        if (nums[r]!=target) return res;
        res[0]=r;
        
        r=n-1;
        while (l<r) {
            mid=l+(r-l)/2+1;
            if (nums[mid]>target) r=mid-1;
            else l=mid;
        }
        res[1]=r;
        return res;
    }
};

