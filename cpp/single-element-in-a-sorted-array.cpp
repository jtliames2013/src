540. Single Element in a Sorted Array
Medium

846

64

Favorite

Share
Given a sorted array consisting of only integers where every element appears exactly twice except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid, next;
        // find the first even-index number not followed by the same number
        while (l<r) {
            mid=l+(r-l)/2;
            next=(mid%2==0)?mid+1:mid-1;
            if (nums[mid]==nums[next]) l=mid+1;
            else r=mid;
        }
        return nums[r];
    }
};
