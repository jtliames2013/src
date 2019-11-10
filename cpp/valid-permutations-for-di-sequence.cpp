903. Valid Permutations for DI Sequence
Hard

203

25

Favorite

Share
We are given S, a length n string of characters from the set {'D', 'I'}. (These letters stand for "decreasing" and "increasing".)

A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0, 1, ..., n}, such that for all i:

If S[i] == 'D', then P[i] > P[i+1], and;
If S[i] == 'I', then P[i] < P[i+1].
How many valid permutations are there?  Since the answer may be large, return your answer modulo 10^9 + 7.

 

Example 1:

Input: "DID"
Output: 5
Explanation: 
The 5 valid permutations of (0, 1, 2, 3) are:
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
 

Note:

1 <= S.length <= 200
S consists only of characters from the set {'D', 'I'}.

dp[i][j] means the number of possible permutations of first i + 1 digits,
where the i + 1th digit is j + 1th smallest in the rest of digits.

1.
class Solution {
public:
    int numPermsDISequence(string S) {
        int n=S.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int i=0; i<=n; ++i) dp[0][i]=1;
        for (int i=1; i<=n; ++i) {
            if (S[i-1]=='I') {
                for (int j=0, curr=0; j<n-i+1; ++j) {
                    curr=(curr+dp[i-1][j])%mod;
                    dp[i][j]=curr;
                }
            } else {
                for (int j=n-i, curr=0; j>=0; --j) {
                    curr=(curr+dp[i-1][j+1])%mod;
                    dp[i][j]=curr;
                }
            }
        }
        return dp[n][0];
    }
private:
    const int mod=1e9+7;
};

2. 1D dp
class Solution {
public:
    int numPermsDISequence(string S) {
        int n=S.size();
        vector<int> dp(n+1, 1);        
        for (int i=1; i<=n; ++i) {
            vector<int> next(n+1);
            if (S[i-1]=='I') {
                for (int j=0, curr=0; j<n-i+1; ++j) {
                    curr=(curr+dp[j])%mod;
                    next[j]=curr;
                }
            } else {
                for (int j=n-i, curr=0; j>=0; --j) {
                    curr=(curr+dp[j+1])%mod;
                    next[j]=curr;
                }
            }
            dp=next;
        }
        return dp[0];
    }
private:
    const int mod=1e9+7;
};

