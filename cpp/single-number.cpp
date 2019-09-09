136. Single Number  QuestionEditorial Solution  My Submissions
Total Accepted: 149841 Total Submissions: 290736 Difficulty: Easy
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

Hide Tags Hash Table Bit Manipulation
Hide Similar Problems (M) Single Number II (M) Single Number III (M) Missing Number (H) Find the Duplicate Number (E) Find the Difference

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int res=nums[0];
        for (int i=1; i<nums.size(); i++) {
            res ^= nums[i];    
        }
        
        return res;
    }
};

