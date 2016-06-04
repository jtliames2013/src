One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false

解法I 利用栈（Stack）数据结构

将元素压入栈

如果当前栈的深度≥3，并且最顶端两个元素为'#', '#'，而第三个元素不为'#'，则将这三个元素弹出栈顶，然后向栈中压入一个'#'，重复此过程

最后判断栈中剩余元素是否只有一个'#'

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
      bool isValidSerialization(string preorder) {
    	  if (preorder.empty()) return false;
    	  vector<string> stk;
    	  istringstream in(preorder);
    	  string val;

    	  while (getline(in, val, ',')) {
    		  stk.push_back(val);
    		  while (stk.size()>=3) {
    			  int size=stk.size();
    			  if (stk[size-1]=="#" && stk[size-2]=="#") {
    				  if (stk[size-3]=="#") return false;
    				  else {
    					  stk.erase(stk.begin()+size-3, stk.end());
    					  stk.push_back("#");
    				  }
    			  } else {
    				  break;
    			  }
    		  }
    	  }

    	  if (stk.size()==1 && stk[0]=="#") return true;
    	  else return false;
      }
  };

int main()
{
	return 0;
}

