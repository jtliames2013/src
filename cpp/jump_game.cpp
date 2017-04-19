55. Jump Game  QuestionEditorial Solution  My Submissions
Total Accepted: 87439 Total Submissions: 303551 Difficulty: Medium
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

Hide Company Tags Microsoft
Hide Tags Array Greedy

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        int n=nums.size();
        int i=0;
        while (i<n && i<=reach) {
            reach=max(reach, i+nums[i]);
            i++;
        }
        return reach>=n-1;
    }
};

