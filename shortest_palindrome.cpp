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

	 void revertString(string& s) {
		 int l=0, r=s.size()-1;
		 while (l<r) {
			 char temp=s[l];
			 s[l]=s[r];
			 s[r]=temp;
			 l++;
			 r--;
		 }
	 }

     string shortestPalindrome(string s) {
    	 string res;
    	 if (s.size()==0) return res;
    	 for (int i=0; i<s.size(); i++) {
    		 if (!isPalindrome(s, i)) {
    			 res=s.substr(i, s.size()-i);
    			 break;
    		 }
    	 }

    	 revertString(res);
    	 res.append(s);
    	 return res;
     }
 };

int main()
{
	return 0;
}

