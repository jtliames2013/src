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
    vector<int> majorityElement(vector<int>& nums) {
    	int size=nums.size();
    	int n1=0, n2=0, c1=0, c2=0;
    	vector<int> res;

    	for (int i=0; i<nums.size(); i++) {
    		if (nums[i]==n1) {
    			c1++;
    		} else if (nums[i]==n2) {
    			c2++;
    		} else {
    			if (c1==0) {
    				n1=nums[i];
    				c1++;
    			} else if (c2==0) {
    				n2=nums[i];
    				c2++;
    			} else {
    				c1--;
    				c2--;
    			}
    		}
    	}

    	c1=0;
    	c2=0;
    	for (int i=0; i<nums.size(); i++) {
    		if (n1==nums[i]) c1++;
    		else if (n2==nums[i]) c2++;
    	}

    	if (c1>size/3) res.push_back(n1);
    	if (c2>size/3) res.push_back(n2);

    	return res;
    }
};

int main()
{
	return 0;
}

