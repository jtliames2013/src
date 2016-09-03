81. Search in Rotated Sorted Array II
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Hide Tags Array Binary Search
Hide Similar Problems (H) Search in Rotated Sorted Array

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
    bool search(vector<int>& nums, int target) {
    	int size=nums.size();
    	if (size==0) return false;

    	int l=0, r=size-1;
    	int mid;

    	while (l<=r) {
    		mid=(l+r)/2;
    		if (nums[mid]==target) return true;
    		if (nums[mid]>nums[l]) {
    			if (nums[l]<=target && target<=nums[mid]) {
    				r=mid-1;
    			} else {
    				l=mid+1;
    			}
    		} else if (nums[mid]<nums[l]) {
    			if (nums[mid]<=target && target<=nums[r]) {
    				l=mid+1;
    			} else {
    				r=mid-1;
    			}
    		} else {
    			// Can only exclude l. Any side may have the target
    			// 3 5 3 3 3
    			// 3 3 3 5 3
    			l++;
    		}
    	}

    	return false;
    }
};

2. Compare with right
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mid;
        
        while (l<=r) {
            mid=l+(r-l)/2;
            if (nums[mid]==target) return true;
            if (nums[mid]<nums[r]) {
                // second half monotonically increase
                if (target>nums[mid]&&target<=nums[r]) l=mid+1;
                else r=mid-1;
            } else if (nums[mid]>nums[r]) {
                // first half monotonically increase
                if (target<nums[mid]&&target>=nums[l]) r=mid-1;
                else l=mid+1;
            } else {
                r--;
            }
        }
        
        return false;
    }
};

int main()
{
	return 0;
}


