215. Kth Largest Element in an Array 
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hide Company Tags Facebook Amazon Microsoft Apple Bloomberg Pocket Gems
Hide Tags Heap Divide and Conquer
Hide Similar Problems

O(n)解法：快速选择（QuickSelect）算法，参考耶鲁大学关于QuickSelect算法的介绍

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
    int findKthLargest(vector<int>& nums, int k) {
    	if (nums.size()==0) return 0;
    	int i = rand()%nums.size();
    	int pivot = nums[i];
    	vector<int> n1, n2;

    	for (int i=0; i<nums.size(); i++) {
    		if (nums[i] > pivot) {
    			n1.push_back(nums[i]);
    		} else if (nums[i] < pivot) {
    			n2.push_back(nums[i]);
    		}
    	}

		if (k <= n1.size()) {
			return findKthLargest(n1, k);
		}
		if (k > nums.size()-n2.size()) {
			return findKthLargest(n2, k-(nums.size()-n2.size()));
		}

		return pivot;
    }
};

2. in-place
class Solution {
public:
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue=nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]);
        int index=left;
        for (int i=left; i<right; i++) {
            if (nums[i]>pivotValue) {
                swap(nums[index], nums[i]);
                index++;
            }
        }
        swap(nums[right], nums[index]);
        return index;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int size=nums.size();
        if (size==0) return 0;
        int left=0, right=size-1;
        while (1) {
            if (left==right) return nums[left];
            int pivotIndex=rand()%(right-left+1)+left;
            pivotIndex=partition(nums, left, right, pivotIndex);
            if (k-1==pivotIndex) return nums[k-1];
            else if (k-1<pivotIndex) right=pivotIndex-1;
            else left=pivotIndex+1;
        }
    }
};

int main()
{
	return 0;
}


