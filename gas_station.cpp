#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

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

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	int s = gas.size();
    	vector<int> left(s, 0);
    	for (int i = 0; i < s; i++)
    	{
    		left[i] = gas[i] - cost[i];
    	}

    	int sum = 0, total = 0;
    	int start = 0;
    	for (int i = 0; i < s; i++)
    	{
    		sum += left[i];
    		total += left[i];
    		if (sum < 0)
    		{
    			sum = 0;
    			start = i+1;
    		}
    	}

    	if (total < 0) return -1;

    	return start;
    }
};

int main()
{
	return 0;
}

