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

无序数组的题目如果要O(n)解法往往要用到hash table，但这题要求constant space。所以可以用数组本身作为一个"hash table"：A[0] = 1, A[1] = 2, .... A[n-1] = n。目标是尽可能将数字i放到数组第i-1个位置。

扫描数组中每个数：
1. 如果A[i]<1或者A[i]>n。说明A[i]一定不是first missing positive。跳过
2. 如果A[i] = i+1，说明A[i]已经在正确的位置，跳过
3. 如果A[i]!=i+1，且0<A[i]<=n，应当将A[i]放到A[A[i]-1]的位置，所以可以交换两数。
这里注意，当A[i] = A[A[i]-1]时会陷入死循环。这种情况下直接跳过。

class Solution {
public:
	void swap(vector<int>& nums, int i, int j) {
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}
    int firstMissingPositive(vector<int>& nums) {
    	int size=nums.size();
    	for (int i=0; i<size; i++) {
    		if (nums[i]>0 && nums[i]<=size) {
    			if (nums[nums[i]-1]!=nums[i]) {
    				swap(nums, nums[i]-1, i);
    				i--;
    			}
    		}
    	}

    	for (int i=0; i<size; i++) {
    		if (nums[i]!=i+1) return i+1;
    	}

    	return size+1;
    }
};

int main()
{
	return 0;
}

