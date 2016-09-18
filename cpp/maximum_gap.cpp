164. Maximum Gap  QuestionEditorial Solution  My Submissions
Total Accepted: 37540 Total Submissions: 134540 Difficulty: Hard
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Sort

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
     int maximumGap(vector<int>& nums) {
    	 int size=nums.size();
    	 if (size<2) return 0;
    	 int maxGap;

    	 int min=nums[0], max=nums[0];
    	 for (int i=1; i<nums.size(); i++) {
    		 if (nums[i]<min) min=nums[i];
    		 if (nums[i]>max) max=nums[i];
    	 }

    	 int bucketRange=(max-min-1)/(size-1)+1;
    	 int bucketLen=(max-min)/bucketRange+1;
    	 vector<int> bucketMin(bucketLen, INT_MAX);
    	 vector<int> bucketMax(bucketLen, 0);
    	 for (int i=0; i<nums.size(); i++) {
    		 int idx= (nums[i]-min)/bucketRange;
    		 if (bucketMin[idx]>nums[i]) bucketMin[idx]=nums[i];
    		 if (bucketMax[idx]<nums[i]) bucketMax[idx]=nums[i];
    	 }

    	 maxGap = bucketMax[0]-bucketMin[0];
    	 int prev=0;
    	 for (int i=1; i<bucketLen; i++) {
    		 if (bucketMin[i]<INT_MAX) {
				 if (bucketMin[i]-bucketMax[prev]>maxGap) {
					 maxGap=bucketMin[i]-bucketMax[prev];
				 }
				 prev=i;
    		 }
    	 }

    	 return maxGap;
     }
 };

int main()
{
	return 0;
}

