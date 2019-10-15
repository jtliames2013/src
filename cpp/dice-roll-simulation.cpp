1223. Dice Roll Simulation
Medium

67

34

Favorite

Share
A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 

Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.

Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
Example 2:

Input: n = 2, rollMax = [1,1,1,1,1,1]
Output: 30
Example 3:

Input: n = 3, rollMax = [1,1,1,2,2,3]
Output: 181
 

Constraints:

1 <= n <= 5000
rollMax.length == 6
1 <= rollMax[i] <= 15

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        if (n<=0) return 0;
        // dp[i][j] the number of sequences of i rolls when
        // the ith roll is j
        vector<vector<long>> dp(n, vector<long>(7));
        for (int i=0; i<6; ++i) {
            dp[0][i]=1;            
        }
        dp[0][6]=6;
        
        for (int i=1; i<n; ++i) {
            long sum=0;
            for (int j=0; j<6; ++j) {
                dp[i][j]=dp[i-1][6];
                if (i-rollMax[j]>=1) {
                    dp[i][j]=(dp[i][j]-(dp[i-rollMax[j]-1][6]-dp[i-rollMax[j]-1][j])+mod)%mod;
                } else if (i-rollMax[j]==0) {
                    dp[i][j]=(dp[i][j]-1)%mod;
                }
                sum=(sum+dp[i][j])%mod;
            }
            dp[i][6]=sum;
        }
        
        return dp[n-1][6];
    }
private:
    const int mod=pow(10,9)+7;
};
