34. Search for a Range Add to List
DescriptionSubmissionsSolutions
Total Accepted: 127071
Total Submissions: 408578
Difficulty: Medium
Contributor: LeetCode
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Subscribe to see which companies asked this question.

Hide Tags Binary Search Array
Hide Similar Problems (E) First Bad Version

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if (nums.size()==0) return res;
        int l=0, r=nums.size()-1, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            if (nums[mid]<target) l=mid+1;
            else r=mid;
        }
        if (nums[l]!=target) return res;
        res[0]=l;
        
        r=nums.size()-1;
        while (l<r) {
            mid=l+(r-l)/2+1;
            if (nums[mid]<=target) l=mid;
            else r=mid-1;
        }
        res[1]=r;
        
        return res;
    }
};

