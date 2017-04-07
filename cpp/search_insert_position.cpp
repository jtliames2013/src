35. Search Insert Position Add to List
DescriptionSubmissionsSolutions
Total Accepted: 159868
Total Submissions: 406931
Difficulty: Easy
Contributor: LeetCode
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

Subscribe to see which companies asked this question.

Hide Tags Array Binary Search
Hide Similar Problems (E) First Bad Version

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid;
        while (l<=r) {
            mid=l+(r-l)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};

