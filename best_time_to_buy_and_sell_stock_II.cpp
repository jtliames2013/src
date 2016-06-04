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
    	int localmin=prices[0];
    	int localmax=prices[0];
    	int maxprofit=0;
    	bool searchmin=true;

    	for (int i=0; i<len; i++)
    	{
    		if (searchmin==true)
    		{
    			if (prices[i] < localmin) localmin=prices[i];
    			else if (prices[i] > localmin)
    			{
    				searchmin=false;
    				localmax=prices[i];
    			}
    		}
    		else
    		{
    			if (prices[i] > localmax) localmax = prices[i];
    			else if (prices[i] < localmax)
    			{
    				searchmin=true;
    				maxprofit += localmax-localmin;
    				localmin=prices[i];
    			}
    		}
    	}

    	if (searchmin==false)
    	{
    		maxprofit += localmax-localmin;
    	}

    	return maxprofit;
    }
};

int main()
{
	return 0;
}

