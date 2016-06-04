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


