31. Next Permutation  
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
Hide Company Tags Google
Hide Tags Array
Hide Similar Problems (M) Permutations (M) Permutations II (M) Permutation Sequence (M) Palindrome Permutation II

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
	void reverse(vector<int>& nums, int start, int end) {
		while (start<end) {
			int temp=nums[start];
			nums[start]=nums[end];
			nums[end]=temp;
			start++;
			end--;
		}
	}

    void nextPermutation(vector<int>& nums) {
    	int index;
    	// find the first non-ascending backwards
    	for (index=nums.size()-1; index>0; index--) {
    		if (nums[index-1]<nums[index]) break;
    	}

    	if (index==0) {
    		reverse(nums, 0, nums.size()-1);
    	} else {
    		int j=index-1;
    		int k;
    		for (k=nums.size()-1; k>=index; k--) {
    			if (nums[k]>nums[j]) break;
    		}

    		int temp=nums[j];
    		nums[j]=nums[k];
    		nums[k]=temp;
    		reverse(nums, index, nums.size()-1);
    	}
    }
};

2. use std swap and reverse
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()<=1) return;
        int index=0;
        for (index=nums.size()-1; index>=0; index--) {
            if (nums[index-1]<nums[index]) break;
        }
        
        if (index==0) {
            reverse(nums.begin(), nums.end());
        } else {
            int k=index-1;
            int j;
            for (j=nums.size()-1; j>=index; j--) {
                if (nums[j]>nums[k]) break;
            }
            swap(nums[k],nums[j]);
            reverse(nums.begin()+index, nums.end());
        }
    }
};

int main()
{
	return 0;
}


