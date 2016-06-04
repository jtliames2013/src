解题思路：
问题可以转化为这样的两个子问题：

1. 从数组nums中挑选出t个数，在保持元素相对顺序不变的情况下，使得选出的子数组最大化。

2. 在保持元素相对顺序不变的前提下，将数组nums1与数组nums2合并，使合并后的数组最大化。
枚举nums1子数组与nums2子数组的长度len1, len2，在满足长度之和len1+len2等于k的前提下，分别求解最大子数组，并进行合并。

然后从合并得到的子数组中取最大数组即为所求。

子问题1的求解：

参考[LeetCode]Remove Duplicate Letters的思路，利用栈保存最大值子数组

时间复杂度为O(n)，其中n为数组的长度。

子问题2的求解：

两数组的合并可以类比归并排序中的merge操作，只不过在选择两数组中较大的元素时，需要对数组剩余部分的元素进行比较，详见代码。

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
	  // get the maximum subarray of num give len <= num.size()
	  vector<int> getMax(vector<int>& num, int len) {
		  vector<int> res;
		  int size=num.size();

		  for (int i=0; i<size; i++) {
			  while (res.size()>0 && res[res.size()-1]<num[i] && res.size()+(size-i)>len) {
				  res.pop_back();
			  }

			  if (res.size()<len) res.push_back((num[i]));
		  }

		  return res;
	  }

	  vector<int> merge(vector<int>& num1, vector<int>& num2) {
		  vector<int> res;
		  int size1=num1.size();
		  int size2=num2.size();
		  int i1=0, i2=0;
		  while (i1<size1 || i2<size2) {
			  if (isFirstGreater(num1, i1, num2, i2)) {
				  res.push_back(num1[i1]);
				  i1++;
			  } else {
				  res.push_back(num2[i2]);
				  i2++;
			  }
		  }

		  return res;
	  }

	  bool isFirstGreater(vector<int>& v1, int i1, vector<int>& v2, int i2) {
		  int size1=v1.size();
		  int size2=v2.size();

		  while (i1<size1 && i2<size2) {
			  if (v1[i1]!=v2[i2]) {
				  return (v1[i1]>v2[i2]);
			  }
			  i1++;
			  i2++;
		  }

		  // if v1 has more, then return true
		  // otherwise v2 has more
		  return (i1!=size1);
	  }

      vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    	  int size1=nums1.size();
    	  int size2=nums2.size();
    	  vector<int> res(k, 0);

    	  for (int i=0; i<=size1; i++) {
    		  if (i<=k && (k-i)<=size2) {
    			  vector<int> n1=getMax(nums1, i);
    			  vector<int> n2=getMax(nums2, k-i);

    			  vector<int> m=merge(n1, n2);
    			  if (!isFirstGreater(res, 0, m, 0)) {
    				  res=m;
    			  }
    		  }
    	  }

    	  return res;
      }
  };

int main()
{
	return 0;
}

