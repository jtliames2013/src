279. Perfect Squares 
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

解法I：数论（Number Theory）

时间复杂度：O(sqrt n)

四平方和定理(Lagrange's Four-Square Theorem)：所有自然数至多只要用四个数的平方和就可以表示。

参考链接：https://leetcode.com/discuss/56982/o-sqrt-n-in-ruby-and-c

class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        for (int a=0; a*a<=n; ++a) {
            int b = sqrt(n - a*a);
            if (a*a + b*b == n)
                return !!a + !!b;
        }
        return 3;
    }
};

2. DP
class Solution {
public:
    int numSquares(int n) {
        if (n<=0) return 0;
        vector<int> dp(n+1, 0);
        for (int i=1; i<=n; i++) {
            int cnt=INT_MAX;
            for (int j=1; j*j<=i; j++) {
                cnt=min(cnt, dp[i-j*j]+1);
            }
            dp[i]=cnt;
        }
        return dp[n];
    }
};

