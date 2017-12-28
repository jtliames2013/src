730. Count Different Palindromic Subsequences
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.

A subsequence of a string S is obtained by deleting 0 or more characters from S.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.

Example 1:
Input: 
S = 'bccb'
Output: 6
Explanation: 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
Example 2:
Input: 
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
Output: 104860361
Explanation: 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
Note:

The length of S will be in the range [1, 1000].
Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.

Let dp[x][i][j] be the answer for the substring S[i...j] where S[i] == S[j] == 'a'+x. Note that since we only have 4 characters a, b, c, d, thus 0 <= x < 4. The DP formula goes as follows:

If S[i] != 'a'+x, then dp[x][i][j] = dp[x][i+1][j], note that here we leave the first character S[i] in the window out due to our definition of dp[x][i][j].

If S[j] != 'a'+x, then dp[x][i][j] = dp[x][i][j-1], leaving the last character S[j] out.

If S[i] == S[j] == 'a'+x, then dp[x][i][j] = 2 + dp[0][i+1][j-1] + dp[1][i+1][j-1] + dp[2][i+1][j-1] + dp[3][i+1][j-1]. When the first and last characters are the same, we need to count all the distinct palindromes (for each of a,b,c,d) within the sub-window S[i+1][j-1] plus the 2 palindromes contributed by the first and last characters.

Let n be the length of the input string S, The final answer would be dp[0][0][n-1] + dp[1][0][n-1] + dp[2][0][n-1] + dp[3][0][n-1] mod 1000000007.

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n=S.size();
        int dp[4][n][3];
        for (int len=1; len<=n; len++) {
            for (int i=0; i+len<=n; i++) {
                for (int x=0; x<4; x++) {
                    int &val=dp[x][i][2]=0;
                    int j=i+len-1;
                    char c='a'+x;
                    if (len==1) val=S[i]==c;
                    else {
                        if (S[i]!=c) val=dp[x][i+1][1];
                        else if (S[j]!=c) val=dp[x][i][1];
                        else {
                            val=2;
                            if (len>2) {
                                for (int y=0; y<4; y++) {
                                    val+=dp[y][i+1][0];
                                    val%=mod;
                                }
                            }
                        }
                    }
                }
            }
            for (int l=0; l<2; l++) {
                for (int i=0; i<n; i++) {
                    for (int x=0; x<4; x++) {
                        dp[x][i][l]=dp[x][i][l+1];
                    }
                }
            }
        }
        int res=0;
        for (int x=0; x<4; x++) res=(res+dp[x][0][2])%mod;
        return res;
    }
private:
    const int mod=1000000007;
};
