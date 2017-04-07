81. Search in Rotated Sorted Array II
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Hide Tags Array Binary Search
Hide Similar Problems (H) Search in Rotated Sorted Array

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mid;
        
        while (l<=r) {
            mid=l+(r-l)/2;
            if (nums[mid]==target) return true;
            if (nums[mid]<nums[r]) {
                // second half monotonically increase
                if (target>nums[mid]&&target<=nums[r]) l=mid+1;
                else r=mid-1;
            } else if (nums[mid]>nums[r]) {
                // first half monotonically increase
                if (target<nums[mid]&&target>=nums[l]) r=mid-1;
                else l=mid+1;
            } else {
                r--;
            }
        }
        
        return false;
    }
};

