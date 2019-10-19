790. Domino and Tromino Tiling
DescriptionHintsSubmissionsDiscussSolution
We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

XX  <- domino

XX  <- "L" tromino
X
Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.

(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)

Example:
Input: 3
Output: 5
Explanation: 
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY
Note:

N  will be in range [1, 1000].

dp[4]=dp[3]+| +  dp[2]+-- + dp[1]+|-| + dp[0]+|--|
            |          --         |_|         |__|

dp[5]=... + dp[0]+|---|
                  |___|


dp[n]=dp[n-1]+dp[n-2]+ 2*(dp[n-3]+…+d[0])
=dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+…+d[0])
=dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+…+d[0]))
=dp[n-1]+dp[n-3]+dp[n-1]
=2*dp[n-1]+dp[n-3]

class Solution {
public:
    int numTilings(int N) {
        int a=0, b=1, c=1, d;
        while (N>1) {
            d=(2*c%mod+a)%mod;
            a=b;
            b=c;
            c=d;
            N--;
        }
        return c;
    }
private:
    const int mod=1e9+7;
};
