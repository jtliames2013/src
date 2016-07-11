283. Move Zeroes  
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Company Tags Bloomberg Facebook
Hide Tags Array Two Pointers
Hide Similar Problems (E) Remove Element

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

 class Solution {
 public:
	 void swap(vector<int>& nums, int s, int e) {
		 int tmp=nums[s];
		 nums[s]=nums[e];
		 nums[e]=tmp;
	 }

     void moveZeroes(vector<int>& nums) {
    	 int size=nums.size();
    	 if (size==0) return;
    	 int start=0;
    	 while (start<size) {
    		 if (nums[start]!=0) start++;
    		 else break;
    	 }
    	 int end=start+1;
    	 while (end<size) {
    		 if (nums[end]==0) end++;
    		 else break;
    	 }

    	 while (end<size) {
    		 swap(nums, start, end);
    		 start++;
    		 while (end<size && nums[end]==0) end++;
    	 }
     }
 };

2. Find the first occurrance of 0, it should be exchanged with numbers after it. 
   Find the the first occurance of nonzero after it. 
   Exchange zero and nonzero.
   zero pointer only moves one step because it either exchange with nonzero next after it or number next after it is also zero.
   nonzero pointer moves to the next nonzero number.

class Solution {
public:
    void swap(vector<int>& nums, int s, int e) {
        int tmp=nums[s];
        nums[s]=nums[e];
        nums[e]=tmp;
    }

    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        int zero=0, nonzero=0;
        
        while (zero<size) {
            if (nums[zero]==0) break;
            zero++;
        }    
        nonzero=zero+1;

        while (nonzero<size) {
            if (nums[nonzero]!=0) break;
            nonzero++;
        }
        
        if (zero<size) {
            while (nonzero<size) {
                swap(nums, zero, nonzero);
                zero++;
                while (nonzero<size && nums[nonzero]==0) nonzero++;
            }
        }
    }
};

int main()
{
	return 0;
}

