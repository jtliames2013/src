322. Coin Change
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

解法I：动态规划（Dynamic Programming）

状态转移方程：

dp[x + c] = min(dp[x] + 1, dp[x + c])
其中dp[x]代表凑齐金额x所需的最少硬币数，c为可用的硬币面值

初始令dp[0] = 0

贪心算法是不正确的，因为有可能会错过全局最优解。


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
#include <math.h>

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
    int coinChange(vector<int>& coins, int amount) {
    	if (amount<=0) return 0;
    	vector<int> dp(amount+1);
    	dp[0]=0;
    	for (int i=1; i<=amount; i++) {
		// amount can't be made up by coins
    		dp[i]=-1;
    	}

    	for (int i=0; i<=amount; i++) {
    		if (dp[i]>=0) {
    			for (int j=0; j<coins.size(); j++) {
    				if (coins[j]+i<=amount) {
    					if (dp[i+coins[j]]<0 || dp[i+coins[j]] > dp[i]+1) {
    						dp[i+coins[j]]=dp[i]+1;
    					}
    				}
    			}
    		}
    	}

    	return dp[amount];
    }
};

int main()
{
	return 0;
}


