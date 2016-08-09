33. Search in Rotated Sorted Array  
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Hide Company Tags LinkedIn Bloomberg Uber Facebook Microsoft
Hide Tags Binary Search Array
Hide Similar Problems (M) Search in Rotated Sorted Array II (M) Find Minimum in Rotated Sorted Array

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

2. Compare with right
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mid;
        
        while (l<=r) {
            mid=l+(r-l)/2;
            if (nums[mid]==target) return mid;
            if (nums[mid]<nums[r]) {
                // second half monotonically increase
                if (target>nums[mid] && target<=nums[r]) l=mid+1;
                else r=mid-1;
            } else {
                // first half monotonically increase
                if (target>=nums[l] && target<nums[mid]) r=mid-1;
                else l=mid+1;
            }
        }
        
        return -1;
    }
};


int main()
{
	return 0;
}

