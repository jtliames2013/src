268. Missing Number  
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Company Tags Microsoft Bloomberg
Hide Tags Array Math Bit Manipulation
Show Similar Problems

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for (auto n:nums) sum+=n;
        return (nums.size()+1)*nums.size()/2-sum;
    }
};

2. Bit operation
a^b^b =a

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0, i=0;
        for (; i<nums.size(); ++i) {
            res=res^nums[i]^i;
        }
        return res^i;
    }
};
