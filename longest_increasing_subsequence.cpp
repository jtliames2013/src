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
    int lengthOfLIS(vector<int>& nums) {
    	int length=nums.size();
    	if (length==0) return 0;
    	vector<int> lislen(length);
    	for (int i=0; i<length; i++) lislen[i]=1;
    	int res=0;

    	for (int i=0; i<length; i++) {
    		for (int j=0; j<i; j++) {
    				if (nums[i]>nums[j]) {
    					lislen[i] = max(lislen[i], lislen[j]+1);
    			}
    		}
    	}

    	for (int i=0; i<length; i++) {
    		if (res < lislen[i]) {
    			res = lislen[i];
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}


