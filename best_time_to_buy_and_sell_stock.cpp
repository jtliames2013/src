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

