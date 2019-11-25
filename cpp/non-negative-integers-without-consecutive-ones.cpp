600. Non-negative Integers without Consecutive Ones
DescriptionHintsSubmissionsSolutions
Total Accepted: 1329
Total Submissions: 5107
Difficulty: Hard
Contributors:
sanxi
Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.

Example 1:
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Note: 1 <= n <= 109

Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming
Hide Similar Problems (E) House Robber (M) House Robber II (M) Ones and Zeroes

The solution is based on 2 facts:

the number of length k string without consecutive 1 is Fibonacci sequence f(k);
For example, if k = 5, the range is 00000-11111. We can consider it as two ranges, which are 00000-01111 and 10000-10111. Any number >= 11000 is not allowed due to consecutive 1. The first case is actually f(4), and the second case is f(3), so f(5)= f(4)+f(3).
Scan the number from most significant digit, i.e. left to right, in binary format. If we find a '1' with k digits to the right, count increases by f(k) because we can put a '0' at this digit and any valid length k string behind; After that, we continue the loop to consider the remaining cases, i.e., we put a '1' at this digit. If consecutive 1s are found, we exit the loop and return the answer. By the end of the loop, we return count+1 to include the number n itself.
For example, if n is 10010110,
we find first '1' at 7 digits to the right, we add range 00000000-01111111, which is f(7);
second '1' at 4 digits to the right, add range 10000000-10001111, f(4);
third '1' at 2 digits to the right, add range 10010000-10010011, f(2);
fourth '1' at 1 digits to the right, add range 10010100-10010101, f(1);
Those ranges are continuous from 00000000 to 10010101. And any greater number <= n will have consecutive 1.

class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0]=1;
        f[1]=2;
        for (int i=2; i<32; ++i) f[i]=f[i-1]+f[i-2];
        
        int res=0, i=30, prev=0;
        for (; i>=0; --i) {
            if (num & (1<<i)) {
                res+=f[i];
                if (prev) return res;
                prev=1;
            } else {
                prev=0;
            }
        }
        
        return res+1;
    }
};

2.
let one[i] be the number of non-consecutive-1 solutions with the i-th significant bit being 1;
let zero[i] be the number of non-consecutive-1 solutions with the i-th significant bit being 0;
the most tricky part is how to count the solutions smaller than num.
We first calculate number of all n-bits solutions: res = one[n - 1] + zero[n - 1].
then we subtract the solutions which is larger than num, we iterate from the MSB to LSB of num:

if bit[i] == 1
if bit[i + 1] == 0, there's no solutions in res that is larger than num, we go further into smaller bit and subtract.
if bit[i + 1] == 1, we know in those res solutions it won't have any consecutive ones. when bit[i + 1] == 1, in one[i + 1], 
the i-th bit in valid solutions must be 0, which are all smaller than 'num', we don't need to check smaller bits and subtract, 
so we break form the loop.
if bit[i] == 0
if bit[i + 1] == 1, there's no solutions in res that is larger than num, we go further into smaller bit and subtract.
if bit[i + 1] == 0, we know zero[i + 1] includes solutions of i-th == 0 (00***) and i-th bit == 1 (01***), we know the i-th bit 
of num is 0, so we need to subtract all the 01*** solutions because it is larger than num. Therefore, one[i] is subtracted 
from res.

class Solution {
public:
    int findIntegers(int num) {
        vector<int> bits;
        for (; num>0; num>>=1) bits.push_back(num&1);
        int n=bits.size();

        vector<int> zero(n), one(n);
        zero[0]=one[0]=1;
        for (int i=1; i<n; ++i) {
            zero[i]=zero[i-1]+one[i-1];
            one[i]=zero[i-1];
        }

        int res=zero[n-1]+one[n-1];
        for (int i=n-2; i>=0; --i) {
            if (bits[i]==0 && bits[i+1]==0) res-=one[i];
            else if (bits[i]==1 && bits[i+1]==1) break;
        }
        return res;
    }
};

