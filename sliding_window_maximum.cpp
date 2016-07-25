239. Sliding Window Maximum  QuestionEditorial Solution  My Submissions
Total Accepted: 30642 Total Submissions: 106967 Difficulty: Hard
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
Follow up:
Could you solve it in linear time?

Hint:

How about using a data structure such as deque (double-ended queue)?
The queue size need not be the same as the window’s size.
Remove redundant elements and the queue should store only elements that need to be considered.
Hide Company Tags Amazon Google Zenefits
Hide Tags Heap
Hide Similar Problems (H) Minimum Window Substring (E) Min Stack (H) Longest Substring with At Most Two Distinct Characters (H) Paint House II

遍历数组nums，使用双端队列deque维护滑动窗口内有可能成为最大值元素的数组下标

由于数组中的每一个元素至多只会入队、出队一次，因此均摊时间复杂度为O(n)

记当前下标为i，则滑动窗口的有效下标范围为[i - (k - 1), i]

若deque中的元素下标＜ i - (k - 1)，则将其从队头弹出，deque中的元素按照下标递增顺序从队尾入队。

这样就确保deque中的数组下标范围为[i - (k - 1), i]，满足滑动窗口的要求。

当下标i从队尾入队时，顺次弹出队列尾部不大于nums[i]的数组下标（这些被弹出的元素由于新元素的加入而变得没有意义）

deque的队头元素即为当前滑动窗口的最大值

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
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>

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
      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	  vector<int> res;
    	  deque<int> index;
    	  int size=nums.size();
    	  for (int i=0; i<size; i++) {
    		  while (!index.empty() && nums[index.back()]<=nums[i]) {
    			  index.pop_back();
    		  }
    		  index.push_back(i);

    		  if (i-index.front()==k) {
    			  index.pop_front();
    		  }

    		  if (i>=k-1) res.push_back(nums[index.front()]);
    	  }

    	  return res;
      }
  };

int main()
{
	return 0;
}

