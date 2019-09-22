1140. Stone Game II
Medium

121

27

Favorite

Share
Alex and Lee continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alex and Lee take turns, with Alex starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alex takes one pile at the beginning, Lee takes two piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles at the beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
 

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10 ^ 4

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int> sums(n);
        sums[n-1]=piles[n-1];
        for (int i=n-2; i>=0; --i) sums[i]=sums[i+1]+piles[i];
        
        vector<vector<int>> dp(n, vector<int>(n));
        return dfs(piles, sums, dp, n, 0, 1);                
    }
private:
    int dfs(vector<int>& piles, vector<int>& sums, vector<vector<int>>& dp, int n, int i, int M) {
        if (i>=n) return 0;
        if (i+2*M>=n) return sums[i];
        if (dp[i][M]!=0) return dp[i][M];
        int mn=INT_MAX;
        for (int x=1; x<=2*M; ++x) {
            mn=min(mn, dfs(piles, sums, dp, n, i+x, max(M, x)));
        }
        
        dp[i][M]=sums[i]-mn;
        return dp[i][M];
    }
};
