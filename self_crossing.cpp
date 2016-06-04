不交叉的有以下三种情况

平行移动的距离是不断的增加的（螺旋形上升）
平行移动的距离是不断的减少的（螺旋形下降）
平行移动的距离先增加后减少，并且再也不增加。

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
      bool isSelfCrossing(vector<int>& x) {
    	  int size=x.size();
    	  if (size<4) return false;

    	  int t1=0, t2=x[0], t3=x[1], t4=x[2], t5;
    	  bool increase = t4 > t2 ? true : false;
    	  for (int i=3; i<size; i++) {
    		  t5=x[i];
    		  if (increase && t5<=t3) {
    			  if (t5+t1<t3 || (i+1<size && x[i+1]+t2<t4)) {
    				  increase=false;
    			  } else if (i+1<size) {
    				  // t5+t1>=t3, x[i+1]+t2>=t4
    				  return true;
    			  }

    		  } else if (!increase && t5>=t3) {
    			  return true;
    		  }

    		  t1=t2;
    		  t2=t3;
    		  t3=t4;
    		  t4=t5;
    	  }

    	  return false;
      }
  };

int main()
{
	return 0;
}

