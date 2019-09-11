122. Best Time to Buy and Sell Stock II  
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Hide Company Tags Bloomberg
Hide Tags Array Greedy
Hide Similar Problems (E) Best Time to Buy and Sell Stock (H) Best Time to Buy and Sell Stock III (H) Best Time to Buy and Sell Stock IV (M) Best Time to Buy and Sell Stock with Cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for (int i=1; i<prices.size(); i++) {
            int diff=prices[i]-prices[i-1];
            if (diff>0) profit+=diff;
        }
        return profit;
    }
};

2.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        int bottom, top;
        for (int i=0; i<n; i++) {
            while (i<n-1 && prices[i]>=prices[i+1]) i++;
            bottom=prices[i];
            while (i<n-1 && prices[i]<=prices[i+1]) i++;
            top=prices[i];
            profit+=top-bottom;
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n==0) return 0;
        int buy=INT_MIN, sell=0;
        for (int i=0; i<n; i++) {
            buy=max(sell-prices[i], buy);
            sell=max(buy+prices[i], sell);
        }
        return sell;
    }
};

