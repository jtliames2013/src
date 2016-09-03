87. Scramble String  QuestionEditorial Solution  My Submissions
Total Accepted: 50846 Total Submissions: 185846 Difficulty: Hard
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Hide Tags Dynamic Programming String

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
     bool isScramble(string s1, string s2) {
    	 if (s1.size()!=s2.size()) return false;
    	 string str1=s1;
    	 sort(str1.begin(), str1.end());
    	 string str2=s2;
    	 sort(str2.begin(), str2.end());
    	 if (str1!=str2) return false;

    	 if (s1.size()==1) return s1==s2;

    	 for (int i=0; i<s1.size()-1; i++) {
    		 if (isScramble(s1.substr(0, i+1), s2.substr(0,i+1)) &&
    			 isScramble(s1.substr(i+1, s1.size()-i-1), s2.substr(i+1, s2.size()-i-1))) {
    			 return true;
    		 }

    		 if (isScramble(s1.substr(0, i+1), s2.substr(s2.size()-i-1, i+1)) &&
				 isScramble(s1.substr(i+1, s1.size()-i-1), s2.substr(0, s2.size()-i-1))) {
				 return true;
			 }
    	 }

    	 return false;
     }
 };

int main()
{
	return 0;
}

