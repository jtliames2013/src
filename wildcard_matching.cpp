44. Wildcard Matching  
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
Hide Company Tags Google Snapchat Facebook
Hide Tags Dynamic Programming Backtracking Greedy String
Hide Similar Problems (H) Regular Expression Matching

[解题思路]
主要是*的匹配问题。p每遇到一个*，就保留住当前*的坐标和s的坐标，然后s从前往后扫描，如果不成功，则s++,重新扫描。

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
     bool isMatch(string s, string p) {
    	 int i=0, j=0;
    	 bool star=false;
    	 int sIndex, pIndex;
    	 while (i<s.size()) {
    		 if (p[j]!='?' && p[j]!='*') {
    			 if (s[i]!=p[j]) {
    				 if (star==false) {
    					 return false;
    				 } else {
    					 j=pIndex;
    					 i=++sIndex;
    				 }
    			 }
    			 else {
    				 i++;
    				 j++;
    			 }
    		 } else if (p[j]=='?') {
    			 i++;
    			 j++;
    		 } else {
    			 while (p[j]=='*') j++;
    			 if (p[j]=='\0') return true;
    			 star=true;
    			 sIndex=i;
    			 pIndex=j;
    		 }
    	 }

    	 while (p[j]=='*') j++;
    	 if (j==p.size()) return true;
    	 else return false;
     }
 };

int main()
{
	string s="ab";
	string p="*a";

	Solution sol;
	sol.isMatch(s, p);
	return 0;
}

