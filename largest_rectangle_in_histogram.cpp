84. Largest Rectangle in Histogram  QuestionEditorial Solution  My Submissions
Total Accepted: 64486 Total Submissions: 261273 Difficulty: Hard
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

Show Tags
Show Similar Problems

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
     int largestRectangleArea(vector<int>& heights) {
    	 int size=heights.size();
    	 if (size==0) return 0;
    	 stack<int> stk;
    	 int maxArea=0;

    	 for (int i=0; i<heights.size(); i++) {
    		 while (!stk.empty() && heights[stk.top()]>heights[i]) {
    			 int h=heights[stk.top()];
    			 stk.pop();
    			 if (stk.empty()) {
    				 maxArea=max(maxArea, i * h);
    			 } else {
    				 maxArea=max(maxArea, (i-stk.top()-1)*h);
    			 }
    		 }

    		 stk.push(i);
    	 }

    	 while (!stk.empty()) {
			 int h=heights[stk.top()];
			 stk.pop();
			 if (stk.empty()) {
				 maxArea=max(maxArea, size * h);
			 } else {
				 maxArea=max(maxArea, (size-stk.top()-1)*h);
			 }
		 }

    	 return maxArea;
     }
 };

这道题让求直方图中最大的矩形，刚开始看到求极值问题以为要用DP来做，可是想不出递推式，只得作罢。这道题如果用暴力搜索法估计肯定没法通过OJ，但是我也没想出好的优化方法，在网上搜到了网友水中的鱼的博客，发现他想出了一种很好的优化方法，就是遍历数组，每找到一个局部峰值，然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值，代码如下：

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (i + 1 < height.size() && height[i] <= height[i + 1]) {
                continue;
            }
            int minH = height[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, height[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }
};

后来又在网上发现一种比较流行的解法，是利用栈来解，可参见网友实验室小纸贴校外版的博客，但是经过仔细研究，其核心思想跟上面那种剪枝的方法有异曲同工之妙，这里维护一个栈，用来保存递增序列，相当于上面那种方法的找局部峰值，当当前值小于栈顶值时，取出栈顶元素，然后计算当前矩形面积，然后再对比当前值和新的栈顶值大小，若还是栈顶值大，则再取出栈顶，算此时共同矩形区域面积，照此类推，可得最大矩形。这两种解法的时间复杂度很依赖于输入数组的情况，在最坏的情况下，比如输入数组是个递减数列，那么此时的时间复杂度会变为O(n^2)。代码如下：

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[s.top()] < height[i]) s.push(i);
            else {
                int cur = s.top();
                s.pop();
                res = max(res, height[cur] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return res;
    }
};

我们可以将上面的方法稍作修改，使其更加简洁一些：

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int cur = s.top(); s.pop();
                res = max(res, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }
};

int main()
{
	return 0;
}

