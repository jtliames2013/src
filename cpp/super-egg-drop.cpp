887. Super Egg Drop
Hard

514

52

Favorite

Share
You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000


dp[M][K]means that, given K eggs and M moves,
what is the maximum number of floor that we can check.

The dp equation is:
dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1,
assume, dp[m-1][k-1] = n0, dp[m-1][k] = n1
the first floor to check is n0+1.
if egg breaks, F must be in [1,n0] floors, we can use m-1 moves and k-1 eggs to find out F is which one.
if egg doesn't breaks and F is in [n0+2, n0+n1+1] floors, we can use m-1 moves and k eggs to find out F is which one.
So, with m moves and k eggs, we can find out F in n0+n1+1 floors, whichever F is.

1. 2D dp
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1, vector<int>(K+1));
        int  m=0;
        while (dp[m][K]<N) {
            m++;
            for (int k=1; k<=K; ++k) {
                dp[m][k]=dp[m-1][k-1]+dp[m-1][k]+1;
            }
        }
        return m;
    }
};

2. 1D dp
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int> dp(K+1);
        int  m=0;
        for(; dp[K]<N; ++m) {            
            for (int k=K; k>0; --k) {
                dp[k]+=dp[k-1]+1;
            }
        }
        return m;
    }
};

