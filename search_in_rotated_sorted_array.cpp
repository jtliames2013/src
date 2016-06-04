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
    int search(vector<int>& nums, int target) {
    	int size=nums.size();
    	if (size==0) return -1;

    	int l=0, r=size-1;
    	int mid;

    	while(l<=r)
    	{
    		mid = (l+r)/2;
    		if (nums[mid]==target) return mid;

    		if (nums[mid]>=nums[l]) {
    			// the left portion is monotonically increasing
    			if (nums[l]<=target && target<=nums[mid]) {
    				r=mid-1;
    			} else {
    				l=mid+1;
    			}
    		} else {
    			// the right portion is monotonically increasing
    			if (nums[mid]<=target && target<=nums[r]) {
    				l=mid+1;
    			} else {
    				r=mid-1;
    			}
    		}
    	}

    	return -1;
    }
};

int main()
{
	return 0;
}

