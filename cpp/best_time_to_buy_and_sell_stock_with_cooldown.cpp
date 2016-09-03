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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

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

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size()==0) return 0;
    	int profit=0;
    	int size=prices.size();
    	vector<int> sell(size, 0);
    	vector<int> buy(size, 0);
    	buy[0]=-prices[0];

    	for (int i=1; i<prices.size(); i++) {
    		sell[i] = max(buy[i-1]+prices[i], sell[i-1]+prices[i]-prices[i-1]);
    		buy[i] = max(i>1 ? sell[i-2]-prices[i] : 0-prices[i], buy[i-1]-prices[i]+prices[i-1]);
    	}

    	for (int i=0; i<sell.size(); i++) {
    		if (profit < sell[i]) profit = sell[i];
    	}

    	return profit;
    }
};

int main()
{
	return 0;
}


