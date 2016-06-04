 Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:

Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:

Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time? 

Solution
Subarray sum also known as Range sum can be defined as the sum of all elements in the range [i, j) where i < j denoted by S(i, j). Note that in this definition, i is inclusive and j is exclusive.

When i = 0, we often call it prefix sum, denoted by S[j] = S(0, j). It is easy to see that

S(i, j) = S[j] – S[i] and 0<= i < n and 0 < j <= n

Therefore if we have all the prefix sums calculated in O(n) any query of S(i, j) is O(1).

This is exactly what we did in the problem Range sum query – Immutable

OK, now let’s consider this problem. Suppose we calculated all the prefix sums and stored it in an array sums then the problem becomes:

maximize j - i
subject to sums[j] - sums[i] = k
This is only a variant of the famous problem two sum. The solution is almost the same


NOTE: sum[j]-sum[i]==k, j must > i, since we sum from left to right.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

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

  // Definition for a point.
  struct Point {
       int x;
       int y;
       Point() : x(0), y(0) {}
       Point(int a, int b) : x(a), y(b) {}
  };

  class Solution {
  public:
      int maxSubArrayLen(vector<int>& nums, int k) {
    	  int res=0;
    	  int size=nums.size();
    	  if (size==0) return 0;
    	  vector<int> sums(size+1, 0);
    	  map<int, int> m;
    	  for (int i=1; i<=size; i++) {
    		  sums[i]=sums[i-1]+nums[i-1];
    		  m[sums[i]]=i;
    	  }

    	  for (int i=0; i<size; i++) {
    		  auto iter = m.find(sums[i]+k);
    		  if (iter!=m.end()) {
    			  res=max(res, iter->second-i);
    		  }
    	  }

    	  return res;
      }
  };

int main()
{
	return 0;
}

