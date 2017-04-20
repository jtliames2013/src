209. Minimum Size Subarray Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 45383 Total Submissions: 164718 Difficulty: Medium
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len=INT_MAX;
        int sum=0;
        for (int l=0, r=0; r<nums.size(); r++) {
            sum+=nums[r];
            if (sum>=s) {
                while (sum>=s) {
                    sum-=nums[l];
                    l++;
                }
                len=min(len, r-l+2);
            }
        }
        
        return len==INT_MAX?0:len;
    }
};

