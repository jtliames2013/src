214. Shortest Palindrome  QuestionEditorial Solution  My Submissions
Total Accepted: 22759 Total Submissions: 109977 Difficulty: Hard
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.

Hide Company Tags Pocket Gems Google
Hide Tags String
Hide Similar Problems (M) Longest Palindromic Substring (E) Implement strStr() (H) Palindrome Pairs


其实思路也很简单：

求字符串s的翻转s_rev
将两个字符串进行拼接：{s}#{s_rev}
找出新字符串中最长公共前缀后缀长度comLen
s_rev.substring(0, s.length() - comLen)就是在原字符串头部插入的子串部分

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
	 bool isPalindrome(string& s, int index) {
		 int l=0, r=index;
		 while (l<r) {
			 if (s[l]!=s[r]) return false;
			 l++;
			 r--;
		 }

		 return true;
	 }

     string shortestPalindrome(string s) {
    	 string res;
    	 int n=s.size();
    	 if (n==0) return s;
    	 for (int i=n-1; i>=0; i--) {
    		 if (isPalindrome(s, i)) {
    			 res=s.substr(i+1);
    			 break;
    		 }
    	 }

    	 reverse(res.begin(), res.end());
    	 res+=s;
    	 return res;
     }
};
