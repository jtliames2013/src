188. Best Time to Buy and Sell Stock IV
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Hide Tags Dynamic Programming
Hide Similar Problems (E) Best Time to Buy and Sell Stock (M) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock III

/**
 * dp[i, j] represents the max profit up until prices[j] using at most i transactions. 
 * dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }
 *          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
 * dp[0, j] = 0; 0 transactions makes 0 profit
 * dp[i, 0] = 0; if there is only one price data point you can't make any transaction.
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if (n<=1) return 0;
        if (k>=n/2) {
            int res=0;
            for (int i=1; i<n; i++) {
                if (prices[i]>prices[i-1]) res+=prices[i]-prices[i-1];
            }
            return res;
        }
        
        vector<vector<int>> dp(k+1, vector<int>(n));
        for (int i=1; i<=k; i++) {
            int localmax=dp[i-1][0]-prices[0];
            for (int j=1; j<n; j++) {
                dp[i][j]=max(dp[i][j-1], prices[j]+localmax);
                localmax=max(localmax, dp[i-1][j]-prices[j]);
            }
        }
        return dp[k][n-1];
    }
};

