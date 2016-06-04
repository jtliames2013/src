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


