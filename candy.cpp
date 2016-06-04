解题思路：
贪心算法（Greedy Algorithm）

评分同时低于左右两边的孩子只需分配一个糖果

评分相同的相邻孩子，分配的糖果可以不同

算法步骤如下：

1. 首先为每一个孩子分配1个糖果

记当前孩子序号为i，糖果数为candies[i]，评分为ratings[i]

2. 从左向右遍历，若ratings[i] > ratings[i - 1]，则令candies[i] = candies[i - 1] + 1

3. 从右向左遍历，若ratings[x] > ratings[x + 1]，则令candies[x] = max(candies[x], candies[x + 1] + 1)

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
     int candy(vector<int>& ratings) {
    	 int size=ratings.size();
    	 if (size==0) return 0;
    	 int res=0;

    	 vector<int> candies(size, 1);

    	 for (int i=1; i<size; i++) {
    		 if (ratings[i]>ratings[i-1]) {
    			 candies[i]=candies[i-1]+1;
    		 }
    	 }

    	 for (int i=size-2; i>=0; i--) {
    		 if (ratings[i]>ratings[i+1]) {
    			 candies[i] = max(candies[i], candies[i+1]+1);
    		 }
    	 }

    	 for (int i=0; i<size; i++) {
    		 res += candies[i];
    	 }

    	 return res;
     }
 };

int main()
{
	return 0;
}


