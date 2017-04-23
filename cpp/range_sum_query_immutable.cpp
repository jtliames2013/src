303. Range Sum Query - Immutable  QuestionEditorial Solution  My Submissions
Total Accepted: 39752 Total Submissions: 154898 Difficulty: Easy
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
Hide Company Tags Palantir
Hide Tags Dynamic Programming
Hide Similar Problems (M) Range Sum Query 2D - Immutable (M) Range Sum Query - Mutable (M) Maximum Size Subarray Sum Equals k

class NumArray {
public:
    NumArray(vector<int> nums) {
        int n=nums.size();
        sums.resize(n+1);
        for (int i=1; i<=n; i++) {
            sums[i]=sums[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

