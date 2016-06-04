经过一个朋友的提醒， 这道题还可以有另一种做法， 基本思路是这样的， 每次迭代以某一个点为基准， 看后面每一个点跟它构成的直线， 维护一个HashMap， key是跟这个点构成直线的斜率的值， 而value就是该斜率对应的点的数量， 计算它的斜率， 如果已经存在， 那么就多添加一个点， 否则创建新的key。 这里只需要考虑斜率而不用考虑截距是因为所有点都是对应于一个参考点构成的直线， 只要斜率相同就必然在同一直线上。 最后取map中最大的值， 就是通过这个点的所有直线上最多的点的数量。 对于每一个点都做一次这种计算， 并且后面的点不需要看扫描过的点的情况了， 因为如果这条直线是包含最多点的直线并且包含前面的点， 那么前面的点肯定统计过这条直线了。 因此算法总共需要两层循环， 外层进行点的迭代， 内层扫描剩下的点进行统计， 时间复杂度是O（n^2), 空间复杂度是哈希表的大小， 也就是O（n), 比起上一种做法用这里用哈希表空间省去了一个量级的时间复杂度。 代码如下：

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
     int maxPoints(vector<Point>& points) {
    	 int maxP=1;
    	 int size=points.size();
    	 if (size==0) return 0;

    	 for (int i=0; i<size-1; i++) {
    		 map<double, int> slopes;
    		 int localmax=1;
    		 int numsame=0;
    		 double slope;
    		 for (int j=i+1; j<size; j++) {
    			 if (points[i].x==points[j].x && points[i].y==points[j].y) {
    				 numsame++;
    				 continue;
    			 } else if (points[i].x==points[j].x) {
    				 slope=INT_MAX;
    			 } else if (points[i].y==points[j].y) {
    				 slope=0;
    			 } else {
    				 slope=(double)(points[i].y-points[j].y)/(double)(points[i].x-points[j].x);
    			 }

    			 if (slopes.find(slope)!=slopes.end()) {
    				 slopes[slope]++;
    			 } else {
    				 slopes[slope]=2;
    			 }
    		 }

    		 for(auto v:slopes) {
    			 localmax=max(localmax, v.second);
    		 }
    		 localmax+=numsame;
    		 maxP=max(maxP, localmax);
    	 }

    	 return maxP;
     }
 };

int main()
{
	return 0;
}

