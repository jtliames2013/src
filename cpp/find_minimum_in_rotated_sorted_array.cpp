153. Find Minimum in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Hide Company Tags Microsoft
Hide Tags Array Binary Search
Hide Similar Problems (H) Search in Rotated Sorted Array (H) Find Minimum in Rotated Sorted Array II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

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

class Solution {
public:
    int findMin(vector<int> &num) {
    	if (num.empty()) return 0;

    	int l = 0, r = num.size() - 1;
    	int m;

    	while (l < r)
    	{
    		if (l == r - 1) return num[l] < num[r] ? num[l] : num[r];
    		m = (l + r) / 2;
    		if (num[m] > num[l] && num[m] > num[r])
    		{
    			l = m;
    		}
    		else
    		{
    			r = m;
    		}
    	}

    	return num[l];
    }
};

2.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1;
        int mid;
        
        while (l<r) {
            mid=(l+r)/2;
            if (nums[mid]<=nums[r]) r=mid;
            else l=mid+1;
        }
        
        return nums[l];
    }
};

int main()
{
	return 0;
}

