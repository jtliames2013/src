920. Number of Music Playlists
Hard

259

32

Favorite

Share
Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a playlist so that:

Every song is played at least once
A song can only be played again only if K other songs have been played
Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
Example 2:

Input: N = 2, L = 3, K = 0
Output: 6
Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
Example 3:

Input: N = 2, L = 3, K = 1
Output: 2
Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
 

Note:

0 <= K < N <= L <= 100

dp[i][j] denotes the solution of i songs with j different songs. So the final answer should be dp[L][N]

Think one step before the last one, there are only cases for the answer of dp[i][j]
case 1 (the last added one is new song): listen i - 1 songs with j - 1 different songs, then the last one is definitely new song with the choices of N - (j - 1).
Case 2 (the last added one is old song): listen i - 1 songs with j different songs, then the last one is definitely old song with the choices of j
if without the constraint of K, the status equation will be
dp[i][j] = dp[i-1][j-1] * (N - (j-1)) + dp[i-1][j] * j

If with the constaint of K, there are also two cases
Case 1: no changes since the last added one is new song. Hence, there is no conflict
Case 2: now we don't have choices of j for the last added old song. It should be updated j - k because k songs can't be chosed from j - 1 to j - k. However, if j <= K, this case will be 0 because only after choosing K different other songs, old song can be chosen.

if (j > k)
dp[i][j] = dp[i-1][j-1] * (N- (j-1)) + dp[i-1][j] * (j-k)
else
dp[i][j] = dp[i-1][j-1] * (N- (j-1))

1.
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long>> dp(L+1, vector<long>(N+1));
        dp[0][0]=1;
        for (int i=1; i<=L; ++i) {
            for (int j=1; j<=N; ++j) {
                dp[i][j]=(dp[i-1][j-1]*(N-j+1))%mod;
                if (j>K) {
                    dp[i][j]=(dp[i][j]+dp[i-1][j]*(j-K)%mod)%mod;
                }
            }
        }
        return dp[L][N];
    }
private:
    const int mod=1e9+7;
};

F(N,L,K) = F(N - 1, L - 1, K) * N + F(N, L - 1, K) * (N - K)

F(N - 1, L - 1, K)
If only N - 1 in the L - 1 first songs.
We need to put the rest one at the end of music list.
Any song can be this last song, so there are N possible combinations.

F(N, L - 1, K)
If already N in the L - 1 first songs.
We can put any song at the end of music list,
but it should be different from K last song.
We have N - K choices.

2.
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long>> dp(N+1, vector<long>(L+1));
        for (int i=K+1; i<=N; ++i) {
            for (int j=i; j<=L; ++j) {
                if (i==j || i==K+1) dp[i][j]=factorial(i);
                else {
                    dp[i][j]=(dp[i-1][j-1]*i+dp[i][j-1]*(i-K))%mod;
                }
            }
        }
        return dp[N][L];
    }
private:
    long factorial(int n) {
        long res=1;
        for (int i=2; i<=n; ++i) {
            res=(res*i)%mod;
        }
        return res;
    }
    const int mod=1e9+7;
};

