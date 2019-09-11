371. Sum of Two Integers 
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

Hide Company Tags Hulu
Hide Tags Bit Manipulation
Hide Similar Problems (M) Add Two Numbers

Sum of two bits can be obtained by performing XOR (^) of the two bits. Carry bit can be obtained by performing AND (&) of two bits. It is simple logic that can be used to add 2 single bits. We can extend this logic for integers. If x and y don’t have set bits at same position(s), then bitwise XOR (^) of x and y gives the sum of x and y. To incorporate common set bits also, bitwise AND (&) is used. Bitwise AND of x and y gives all carry bits. We calculate (x & y) << 1 and add it to x ^ y to get the required result.

class Solution {
public:
    int getSum(int a, int b) {
        while (b!=0) {
            unsigned int carry=a&b;
            a^=b;
            b=carry<<1;
        }
        return a;
    }
};
