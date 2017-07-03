629. K Inverse Pairs Array
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.

We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.

Since the answer may very large, the answer should be modulo 109 + 7.

Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: 
Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: 
The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
Note:
The integer n is in the range [1, 1000] and k is in the range [0, 1000].

Let's try for a top-down dp. Suppose we know dp[n][k], the number of permutations of (1...n) with k inverse pairs.

Looking at a potential recursion for dp[n+1][k], depending on where we put the element (n+1) in our permutation, we may add 0, 1, 2, ..., n new inverse pairs. For example, if we have some permutation of 1...4, then:

5 x x x x creates 4 new inverse pairs
x 5 x x x creates 3 new inverse pairs
...
x x x x 5 creates 0 new inverse pairs
where in the above I'm representing any permutation of 1...4 with x's.
Thus, dp[n+1][k] = sum_{x=0..n} dp[n][k-x].

Look back to the above formula.

dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2] + ..... +dp[i-1][j - i + 1]
Let's consider this example
if i = 5

dp[i][0] = dp[i-1][0] (creates 0 inverse pair)
dp[i][1] = dp[i-1][0] (1) + dp[i-1][1] (0)  =  dp[i][0] + dp[i-1][1]
dp[i][2] = dp[i-1][0] (2) + dp[i-1][1] (1) + dp[i-1][2] (0) = dp[i][1] + dp[i-1][2]
.
.
.
dp[i][4] = dp[i-1][0] (4) + dp[i-1][1] (3) + dp[i-1][2] (2) + dp[i-1][3] (1) + dp[i-1][4] (0)  = dp[i][3] + dp[i-1][4]
Can you find the rules about above formula.
if j < i , we can compute dp[i][j] = dp[i][j-1] +dp[i-1][j]

So, how about j >= i
We know if we add number i into permutation(0 .. i -1 ), i can create 0 ~i -1 inverse pair
If j >= i , we still use dp[i][j] = dp[i][j-1] +dp[i-1][j].
We must minus dp[i][j-i]. (In fact it minusdp[i-1][j-i], because everyj >= iin dp vecor,it minus dp[i-1][j-i]individually)
For example, if i = 5

dp[i][5] = dp[i][4] + dp[i-1][5] - dp[i-1][0]
dp[i][6] = dp[i][5] + dp[i-1][6] - dp[i-1][1]

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 1;
            for(int j = 1; j <= k; j++){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
                if(j - i >= 0){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod;                     
                }
            }
        }
        return dp[n][k];    
    }
private:
    const int mod = pow(10, 9) + 7;    
};

