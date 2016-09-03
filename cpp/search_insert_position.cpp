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
    int searchInsert(vector<int>& nums, int target) {
    	if (nums.size() == 0) return 0;

    	int i;
    	for (i=0; i<nums.size(); i++)
    	{
    		if (nums[i] >= target) break;
    	}

    	return i;
    }
};

Binary search的变种。如果target存在于数组中，则binary search就能找到。关键在于target不在数组中，当binary search结束时：start > end时，究竟应该如何获得插入位置。这里考察的是对base case的分析。定义insertion index为p，两种base case情况：

1. start = end = mid：
a. target < A[mid]，则我们知道p = mid。
binary search下一步会搜索A[start = mid : end = mid-1]而终止，在这一步应该返回start。
b. 反之target > A[mid]，则我们知道p = mid+1。
binary search下一步会搜索A[start = mid+1 : end = mid]而终止，这一步我们仍旧应该返回start。

2. start = end-1 = mid：
a. target < A[mid]，则我们知道p = mid。
同1a情况，查找结束start > end时，返回start
b. target > A[mid]，则我们知道p = mid+1或mid+2
binary search下一步会搜索A[start = mid+1 : end = mid+1]，即base case 1的情况。

综上所述，该问题的解法思路如下：
1. Binary search整个数组，如果在start <= end时找到了target，返回mid
2. 如果查找失败，即start > end，返回start即可。

2. binary search
class Solution {

public:

    int searchInsert(vector<int>& nums, int target) {

        int size=nums.size();

        int l=0, r=size-1;

        int m;

        while (l<=r) {

            m=(l+r)/2;

            if (nums[m]==target) return m;

            else if (nums[m]<target) l=m+1;

            else r=m-1;

        }

        return l;

    }

};

int main()
{
	return 0;
}

