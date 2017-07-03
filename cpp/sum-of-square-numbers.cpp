633. Sum of Square Numbers
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i=0; i<=sqrt(c); i++) {
            if (floor(sqrt(c-i*i))==sqrt(c-i*i)) return true;
        }
        return false;
    }
};

