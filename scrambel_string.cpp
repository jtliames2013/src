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

