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


