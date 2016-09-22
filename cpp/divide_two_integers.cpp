29. Divide Two Integers  
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

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
    int divide(int dividend, int divisor) {
    	if (divisor==0) {
    		if (dividend>0) return INT_MAX;
    		else return INT_MIN;
    	}

    	if (dividend==INT_MIN && divisor==-1) return INT_MAX; //INT_MIN+INT_MIN=0 due to overflow
    	int res=0;
    	bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

    	unsigned long long dd = abs((long long)dividend);
    	unsigned long long dr = abs((long long)divisor);

    	while (dd >= dr) {
    		int i=0;
			while ((dr << i+1) < dd) {
				i++;
			}
			res += 1 << i;
			dd -= (dr << i);
    	}

    	if (neg) res = -res;

    	return res;
    }
};

int main()
{
	return 0;
}


