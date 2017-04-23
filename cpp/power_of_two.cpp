231. Power of Two Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 129025
Total Submissions: 324675
Difficulty: Easy
Contributor: LeetCode
Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Math Bit Manipulation
Hide Similar Problems (E) Number of 1 Bits (E) Power of Three (E) Power of Four

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 && (n&(n-1))==0);
    }
};
