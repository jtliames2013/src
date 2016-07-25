238. Product of Array Except Self
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Hide Company Tags Amazon LinkedIn Apple Facebook Microsoft
Hide Tags Array
Hide Similar Problems (H) Trapping Rain Water (M) Maximum Product Subarray (H) Paint House II

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
    vector<int> productExceptSelf(vector<int>& nums) {
    	int product=1;
    	int size = nums.size();
    	vector<int> res(size);
    	for (int i=0; i<size; i++) {
    		res[i] = product;
    		product *= nums[i];
    	}

    	product=1;
    	for (int i=size-1; i>=0; i--) {
    		res[i] *= product;
    		product *= nums[i];
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

