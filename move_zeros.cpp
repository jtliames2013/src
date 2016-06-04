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

int main()
{
	return 0;
}

