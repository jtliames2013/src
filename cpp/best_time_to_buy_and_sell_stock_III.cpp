123. Best Time to Buy and Sell Stock III
DescriptionHintsSubmissionsSolutions
Total Accepted: 84228
Total Submissions: 291117
Difficulty: Hard
Contributor: LeetCode
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question.

Hide Tags Array Dynamic Programming
Hide Similar Problems (E) Best Time to Buy and Sell Stock (E) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1=INT_MIN, buy2=INT_MIN, sell1=0, sell2=0;
        for (auto p:prices) {
            buy1=max(buy1, -p);
            sell1=max(sell1, buy1+p);
            buy2=max(buy2, sell1-p);
            sell2=max(sell2, buy2+p);            
        }
        return sell2;
    }
};

