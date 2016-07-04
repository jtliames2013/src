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

解法II：广度优先搜索（BFS）

参考：https://leetcode.com/discuss/76432/fast-python-bfs-solution

将问题转化为求X轴0点到坐标点amount的最短距离（每次向前行进的合法距离为coin的面值）

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

    	vector<int> v1, v2;
    	int count=0;
    	vector<bool> visited(amount+1);
    	v1.push_back(0);
    	visited[0]=true;

    	while (!v1.empty()) {
    		count++;
    		for (int i=0; i<v1.size(); i++) {
				for (int j=0; j<coins.size(); j++) {
					if (v1[i]+coins[j]==amount) return count;
					else if (v1[i]+coins[j]<amount) {
						if (visited[v1[i]+coins[j]] == false) {
							v2.push_back(v1[i]+coins[j]);
							visited[v1[i]+coins[j]]=true;
						}
					}
				}
    		}

    		v1.clear();
    		for (int i=0; i<v2.size(); i++) v1.push_back(v2[i]);
    		v2.clear();
    	}

    	return -1;
    }
};

int main()
{
	return 0;
}


