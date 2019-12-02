479. Largest Palindrome Product
Hard

76

1262

Favorite

Share
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

 

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

 

Note:

The range of n is [1,8].

class Solution {
public:
    int largestPalindrome(int n) {
        if (n==1) return 9;
        int lower=pow(10, n-1), upper=pow(10, n)-1;
        for (int i=upper; i>=lower; --i) {
            long num=getPalin(i);
            for (long j=upper; j*j>=num; --j) {
                if (num%j==0 && num/j<=upper) return num%1337;
            }
        }
        return -1;
    }
private:
    long getPalin(int n) {
        string s=to_string(n), rev=s;
        reverse(rev.begin(), rev.end());
        return stol(s+rev);
    }
};

