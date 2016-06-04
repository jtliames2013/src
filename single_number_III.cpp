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
    vector<int> singleNumber(vector<int>& nums) {
    	vector<int> res;
    	int twonums=0;
    	for (int i=0; i<nums.size(); i++) {
    		twonums ^= nums[i];
    	}

    	int index=0;
    	if (twonums==0) {
    		res.push_back(twonums);
    		res.push_back(twonums);
    		return res;
    	}
    	while ((twonums & (1 << index)) == 0) {
    		index++;
    	}

    	int b=0;
    	for (int i=0; i<nums.size(); i++) {
    		if ((nums[i] & (1 << index)) != 0) {
    			b ^= nums[i];
    		}
    	}

    	int c=b^twonums;
    	res.push_back(b);
    	res.push_back(c);
    	return res;
    }
};

int main()
{
	return 0;
}


