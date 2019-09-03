191. Number of 1 Bits  QuestionEditorial Solution  My Submissions
Total Accepted: 107005 Total Submissions: 283260 Difficulty: Easy
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Company Tags Microsoft Apple
Hide Tags Bit Manipulation
Hide Similar Problems (E) Reverse Bits (E) Power of Two (M) Counting Bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while (n>0) {
            res+=(n & 0x1);
            n>>=1;
        }
        return res;
    }
};

2.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        while (n!=0) {
            sum++;
            n &= (n-1);
        }
        return sum;
    }
};

