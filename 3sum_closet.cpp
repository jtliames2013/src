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
	int abs(int num) {
		return num>=0 ? num : 0 - num;
	}

    int threeSumClosest(vector<int>& nums, int target) {
    	int sum = 0;
    	int gap = INT_MAX;
    	if (nums.size()==0) return  0;
    	int start, end;
    	sort(nums.begin(), nums.end());

    	for (int i=0; i<nums.size()-1; i++) {
    		start=i+1;
    		end=nums.size()-1;

    		while (start<end) {
    			int absolute = abs(nums[i]+nums[start]+nums[end]-target);
    			if (nums[i]+nums[start]+nums[end]==target) {
    				return target;
    			} else if (nums[i]+nums[start]+nums[end]>target) {
    				if (absolute<gap) {
    					sum=nums[i]+nums[start]+nums[end];
    					gap=absolute;
    				}
    				end--;
    			} else {
    				if (absolute<gap) {
    					sum=nums[i]+nums[start]+nums[end];
    					gap=absolute;
    				}
    				start++;
    			}
    		}
    	}

    	return sum;
    }
};

int main()
{
	return 0;
}


