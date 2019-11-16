1259. Handshakes That Don't Cross
Hard

2

0

Favorite

Share
You are given an even number of people num_people that stand around a circle and each person shakes hands with someone else, so that there are num_people / 2 handshakes total.

Return the number of ways these handshakes could occur such that none of the handshakes cross.

Since this number could be very big, return the answer mod 10^9 + 7

 

Example 1:

Input: num_people = 2
Output: 1
Example 2:



Input: num_people = 4
Output: 2
Explanation: There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].
Example 3:



Input: num_people = 6
Output: 5
Example 4:

Input: num_people = 8
Output: 14
 

Constraints:

2 <= num_people <= 1000
num_people % 2 == 0

class Solution {
public:
    int numberOfWays(int num_people) {
        int n=num_people/2;
        vector<long> dp(n+1);
        dp[0]=1;
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                dp[i]=(dp[i]+dp[j]*dp[i-1-j])%mod;
            }
        }
        return dp[n];
    }
private:
    const int mod=1e9+7;
};

