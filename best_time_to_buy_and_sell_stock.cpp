121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
Hide Company Tags Amazon Microsoft Bloomberg Uber Facebook
Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Maximum Subarray (M) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock III (H) Best Time to Buy and Sell Stock IV (M) Best Time to Buy and Sell Stock with Cooldown

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int len = prices.size();
    	if (len==0) return 0;
    	int maxprice=prices[len-1];
    	int maxprofit=0;
    	int profit;

    	for (int i=len-2; i>=0; i--)
    	{
    		profit = maxprice - prices[i];
    		if (profit > maxprofit) maxprofit = profit;
    		if (maxprice < prices[i]) maxprice = prices[i];
    	}

    	return maxprofit;
    }
};

int main()
{
	return 0;
}

