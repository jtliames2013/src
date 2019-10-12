309. Best Time to Buy and Sell Stock with Cooldown  
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Dynamic Programming
Hide Similar Problems (E) Best Time to Buy and Sell Stock (M) Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n==0) return 0;
        int buy=INT_MIN, sell=0;
        int prevbuy, prevsell=0;
        
        for (int i=0; i<n; i++) {
            prevbuy=buy;
            buy=max(prevsell-prices[i], buy);
            prevsell=sell;
            sell=max(prevbuy+prices[i], sell);
        }
        
        return sell;
    }
};

2.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n==0) return 0;
        vector<int> buy(n, 0), sell(n, 0);
        buy[0]=-prices[0];
        
        for (int i=1; i<n; i++) {
            buy[i]=max((i>1?sell[i-2]:0)-prices[i], buy[i-1]);
            sell[i]=max(buy[i-1]+prices[i], sell[i-1]);
        }
        
        return sell[n-1];
    }
};

