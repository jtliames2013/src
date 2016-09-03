这道题一打开又是图又是这么长的题目的，看起来感觉应该是一道相当复杂的题，但是做完之后发现也就那么回事，虽然我不会做，是学习的别人的解法。这道求天际线的题目应该算是比较新颖的题，要是非要在之前的题目中找一道类似的题，也就只有 Merge Intervals 合并区间了吧，但是与那题不同的是，这道题不是求被合并成的空间，而是求轮廓线的一些关键的转折点，这就比较复杂了，我们通过仔细观察题目中给的那个例子可以发现，要求的红点都跟每个小区间的左右区间点有密切的关系，而且进一步发现除了每一个封闭区间的最右边的结束点是楼的右边界点，其余的都是左边界点，而且每个红点的纵坐标都是当前重合处的最高楼的高度。在网上搜了很多帖子，发现网友百草园的博客上的解法最简洁且易懂，这里完全按照其解法来的。这里用到了multiset数据结构，其好处在于其中的元素是按堆排好序的，插入新元素进去还是有序的，而且执行删除元素也可方便的将所有相同的元素删掉。这里为了区分左右边界，将左边界的高度存为负数，这样遇到左边界就存入堆中，遇到右边界就删掉，然后看当前状态有无改变，改变了话就把左边界和当前的高度存入结果中，具体实现参看代码如下：


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
      vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    	  vector<pair<int, int> > res;
    	  vector<pair<int, int> > lines;
    	  for (auto b : buildings) {
    		  // left has negative height
    		  lines.push_back({b[0], -b[2]});
    		  lines.push_back({b[1], b[2]});
    	  }
    	  sort(lines.begin(), lines.end());
    	  multiset<int> height;
    	  // insert the base line, to be used when no line
    	  height.insert(0);

    	  int prev=0, curr=0;
    	  for (auto l : lines) {
    		  if (l.second < 0) height.insert(-l.second);
    		  else height.erase(height.find(l.second));

    		  curr=*(height.rbegin());
    		  if (curr!=prev) {
    			  res.push_back({l.first, curr});
    			  prev=curr;
    		  }
    	  }

    	  return res;
      }
  };

int main()
{
	return 0;
}


