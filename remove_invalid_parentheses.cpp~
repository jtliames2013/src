这道题让我们移除最少的括号使得给定字符串为一个合法的含有括号的字符串，我们从小数学里就有括号，所以应该对合法的含有括号的字符串并不陌生，字符串中的左右括号数应该相同，而且每个右括号左边一定有其对应的左括号，而且题目中给的例子也说明了去除方法不唯一，我们需要找出所有合法的取法。参考了网上大神的解法，这道题首先可以用BFS来解，我们先把给定字符串排入队中，然后取出检测其是否合法，若合法直接返回，不合法的话，我们对其进行遍历，对于遇到的左右括号的字符，我们去掉括号字符生成一个新的字符串，如果这个字符串之前没有遇到过，将其排入队中，我们用哈希表记录一个字符串是否出现过。我们对队列中的每个元素都进行相同的操作，直到队列为空还没找到合法的字符串的话，那就返回空集，参见代码如下：

())() -> ()+()

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
	  bool isValid(string s) {
		  int count=0;
		  for (int i=0; i<s.size(); i++) {
			  if (s[i]=='(') count++;
			  else if (s[i]==')') {
				  if (count==0) return false;
				  count--;
			  }
		  }

		  return count==0;
	  }

	  vector<string> removeInvalidParentheses(string s) {
    	  vector<string> res;
    	  unordered_set<string> visited;
    	  queue<string> q;
    	  q.push(s);
    	  visited.insert(s);

    	  bool found=false;
    	  while (!q.empty()) {
    		  string str=q.front();
    		  q.pop();

    		  if (isValid(str)) {
    			  res.push_back(str);
    			  found=true;
    		  }

    		  // still search the same level but stop search the next level
    		  if (found) continue;
    		  for (int i=0; i<str.size(); i++) {
    			  if (str[i]!='(' && str[i]!=')') continue;
    			  string tmp=str.substr(0,i)+str.substr(i+1);
    			  if (visited.find(tmp)==visited.end()) {
    				  visited.insert(tmp);
    				  q.push(tmp);
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

