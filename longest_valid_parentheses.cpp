32. Longest Valid Parentheses  QuestionEditorial Solution  My Submissions
Total Accepted: 69635 Total Submissions: 305967 Difficulty: Hard
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Hide Tags Dynamic Programming String
Hide Similar Problems (E) Valid Parentheses

括号题自然又想到了stack。仔细想下，这题目其实是Valid Parentheses的升级版。一个valid parentheses substring必然以'('开头以')'结尾，并且中间一定也是一个valid parentheses substring。这也意味着依照Valid Parentheses解法那样，用stack来存储没有配对的'('和')'，并用相应的')'来消去stack top的'('，最长substring的首尾必然会在这个过程中相消。

1. 由于我们需要知道它们之间的长度，所以stack里可以存储各个'('的坐标。
2. 为了能正确计算类似“ ) ( ) ( ) ”这种valid substring连接而组成的valid substring。我们必须也插入')'进stack，作为边界来计算长度。
3. 为了能在stack中区分左右括号，每个插入item定义为pair<int,int>。first为坐标，second表示左还是右括号。


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
     int longestValidParentheses(string s) {
    	 stack<pair<int, bool>> stk; // left -> true, right->false
    	 int maxlen=0, curlen=0;

    	 for (int i=0; i<s.size(); i++) {
    		 if (s[i]=='(') {
    			 stk.push(make_pair(i, true));
    		 } else {
    			 if (stk.empty() || stk.top().second==false) {
    				 stk.push(make_pair(i, false));
    			 } else {
    				 stk.pop();
    				 if (stk.empty()) {
    					 curlen = i+1;
    				 } else {
    					 curlen = i-stk.top().first;
    				 }

    				 if (curlen > maxlen) maxlen=curlen;
    			 }
    		 }
    	 }

    	 return maxlen;
     }
 };

int main()
{
	return 0;
}

