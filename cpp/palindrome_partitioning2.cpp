use DFS. If the prefix is panlindrome, then recursively search for the test.

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
	 bool isPalindrome(string& s, int start, int end) {
		 while (start<end) {
			 if (s[start]!=s[end]) return false;
			 start++;
			 end--;
		 }

		 return true;
	 }

	 void findPartition(string& s, vector<vector<string> >& res, vector<string>& part, int start) {
		 if (start==s.size()) {
			 res.push_back(part);
			 return;
		 }

		 for (int i=start; i<s.size(); i++) {
			 if (isPalindrome(s, start, i)) {
				 part.push_back(s.substr(start, i-start+1));
				 findPartition(s, res, part, i+1);
				 part.pop_back();
			 }
		 }
	 }

     vector<vector<string>> partition(string s) {
    	 vector<vector<string> > res;
    	 vector<string> part;

    	 findPartition(s, res, part, 0);

    	 return res;
     }
 };

int main()
{
	return 0;
}

