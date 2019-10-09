137. Single Number II  QuestionEditorial Solution  My Submissions
Total Accepted: 94790 Total Submissions: 242820 Difficulty: Medium
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

Hide Tags Bit Manipulation
Hide Similar Problems (E) Single Number (M) Single Number III

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32, 0);
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<32; j++) {
                count[j] += (nums[i] & (0x1<<j))?1:0;
            }
        }
        
        int res=0;
        for (int i=0; i<32; i++) {
            if (count[i]%3!=0) res |= (0x1<<i);
        }
        return res;
    }
};

