476. Number Complement Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 33518
Total Submissions: 54636
Difficulty: Easy
Contributors:
love_Fawn
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
Subscribe to see which companies asked this question.

Hide Tags Bit Manipulation

class Solution {
public:
    int findComplement(int num) {
        unsigned mask=~0;
        while (num & mask) mask<<=1;
        return ~mask & ~num;
    }
};

2.
class Solution {
public:
    int findComplement(int num) {
        int n=num, i=0;
        while (n>0) {
            n>>=1;
            i++;
        }

        return ~num & ((1<<i)-1);
    }
};

