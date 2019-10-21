33. Search in Rotated Sorted Array  
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Hide Company Tags LinkedIn Bloomberg Uber Facebook Microsoft
Hide Tags Binary Search Array
Hide Similar Problems (M) Search in Rotated Sorted Array II (M) Find Minimum in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid;
        while (l<=r) {
            mid=l+(r-l)/2;
            if (nums[mid]==target) return mid;
            if (nums[mid]<nums[r]) {
                // second half monotonically increase                
                if (target>nums[mid] && target<=nums[r]) l=mid+1;
                else r=mid-1;
            } else {
                // first half monotonically increase
                if (target>=nums[l] && target<nums[mid]) r=mid-1;
                else l=mid+1;
            }
        }
        
        return -1;
    }
};

