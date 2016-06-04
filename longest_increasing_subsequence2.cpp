 Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity? 

维护一个单调序列

遍历nums数组，二分查找每一个数在单调序列中的位置，然后替换之。


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

    	vector<int> sorted;

    	for (int i=0; i<nums.size(); i++) {
    		int l=0;
    		int r=sorted.size()-1;
    		int mid;

    		while (l<=r) {
    			mid=(l+r)/2;
    			if (sorted[mid]<nums[i]) l=mid+1;
    			else r=mid-1;
    		}

    		if (l>=sorted.size()) {
    			sorted.push_back(nums[i]);
    		} else if (l>r){
    			sorted[l]=nums[i];
    		}
    	}

    	return sorted.size();
    }
};

int main()
{
	return 0;
}


