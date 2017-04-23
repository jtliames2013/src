342. Power of Four Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 59259
Total Submissions: 155856
Difficulty: Easy
Contributor: LeetCode
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

Credits:
Special thanks to @yukuairoy for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Bit Manipulation
Hide Similar Problems (E) Power of Two (E) Power of Three

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num>0 && (num&(num-1))==0 && (num&0x55555555)>0);
    }
};
