190. Reverse Bits  QuestionEditorial Solution  My Submissions
Total Accepted: 73362 Total Submissions: 248876 Difficulty: Easy
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Company Tags Apple Airbnb
Hide Tags Bit Manipulation
Hide Similar Problems (E) Number of 1 Bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for (int i=0; i<32; i++) {
            res<<=1;
            res|=(n & 0x1);
            n>>=1;
        }
        return res;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

