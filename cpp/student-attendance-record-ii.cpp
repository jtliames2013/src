552. Student Attendance Record II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 1939
Total Submissions: 6816
Difficulty: Hard
Contributors:
fallcreek
Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:
Input: n = 2
Output: 8 
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
Note: The value of n won't exceed 100,000.

Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming
Hide Similar Problems (E) Student Attendance Record I

class Solution {
public:
    int checkRecord(int n) {
        const int mod = 1000000007;
        int dp[n+1][2][3];
    
        for (int i=0; i<=n; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<3; k++) {
                    if (i==0) dp[i][j][k]=1;
                    else {
                        // append P
                        int val=dp[i-1][j][2];
                        // append A
                        if (j>0) val=(val+dp[i-1][j-1][2])%mod;
                        // append L
                        if (k>0) val=(val+dp[i-1][j][k-1])%mod;
                        dp[i][j][k] = val;
                    }
                }
            }
        }
        return dp[n][1][2];        
    }
};

Let f[i][j][k] denote the # of valid sequences of length i where:

There can be at most j A's in the entire sequence.
There can be at most k trailing L's.

f[i][0][0]   | 0 0 1 0 0 0 |   f[i-1][0][0]
f[i][0][1]   | 1 0 1 0 0 0 |   f[i-1][0][1]
f[i][0][2] = | 0 1 1 0 0 0 | * f[i-1][0][2]
f[i][1][0]   | 0 0 1 0 0 1 |   f[i-1][1][0]
f[i][1][1]   | 0 0 1 1 0 1 |   f[i-1][1][1]
f[i][1][2]   | 0 0 1 0 1 1 |   f[i-1][1][2]

Let A be the matrix above, then f[n][][] = A^n * f[0][][], where f[0][][] = [1 1 1 1 1 1]. The point of this approach is that we can compute A^n using exponentiating by squaring (thanks to @StefanPochmann for the name correction), which will take O(6^3 * log n) = O(log n) time. Therefore, the runtime improves to O(log n), which suffices to handle the case for much larger n, say 10^18.
Update: The final answer is f[n][1][2], which involves multiplying the last row of A^n and the column vector [1 1 1 1 1 1]. Interestingly, it is also equal to A^(n+1)[5][2] as the third column of A is just that vector. Credit to @StefanPochmann.

The top row says that:

f[i][0][0] = f[i-1][0][2]
Why? We want at most 0 trailing L's, so the previous (i-1) case where we allow 0, 1, or 2 L's, we can simply add a 'P', and that get's the current (i) case. We don't need any of the f[i-1][1][x] cases, since we don't allow A's. And we don't need the f[i-1][0] and f[i-1][1] cases because those are already counted in the f[i-1][2] case.

Moving on:

f[i][0][1] = f[i-1][0][0] + f[i-1][0][2]
Why? We want at most 1 trailing L, so we can either take a case with no L's (f[i-1][0]) and add an 'L', or we can take one with up to 2 L's (f[i-1][2]) and add a 'P'. f[i-1][0][1] isn't included here because adding an 'L' to it would give us 2 L's, which is outside the desired k of 1, and adding a 'P' to it is already covered by f[i-1][2], which covers 0, 1, or 2 trailing L's.


