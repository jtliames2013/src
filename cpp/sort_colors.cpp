75. Sort Colors  
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
Hide Company Tags Pocket Gems Microsoft Facebook
Hide Tags Array Two Pointers Sort
Hide Similar Problems (M) Sort List (M) Wiggle Sort (M) Wiggle Sort II

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
	void swap(vector<int>& nums, int i, int j)
	{
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}

    void sortColors(vector<int>& nums) {
    	if (nums.size()==0) return;
    	int begin=0, end=nums.size()-1;
    	int i=0;

    	while (i<=end)
    	{
    		if (nums[i]==0)
    		{
    			swap(nums, i, begin);
    			i++;
    			begin++;
    		}
    		else if(nums[i]==2)
    		{
    			swap(nums, i, end);
    			end--;
    		}
    		else
    		{
    			i++;
    		}
    	}
    }
};

2.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0, start=0, end=n-1;
        
        while (i<=end) {
            if (nums[i]==0) {
                if (nums[start]!=0) swap(nums[start], nums[i]);
                start++;
                i++;
            } else if (nums[i]==2) {
                if (nums[end]!=2) swap(nums[i], nums[end]);
                end--;
            } else {
                i++;
            }
        } 
    }
};
int main()
{
	return 0;
}

