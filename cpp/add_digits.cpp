258. Add Digits
DescriptionHintsSubmissionsSolutions
Total Accepted: 162208
Total Submissions: 318666
Difficulty: Easy
Contributor: LeetCode
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Math
Hide Similar Problems (E) Happy Number

https://en.wikipedia.org/wiki/Digital_root

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

