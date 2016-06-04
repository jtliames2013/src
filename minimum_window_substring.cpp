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
     string minWindow(string s, string t) {
    	 map<char, int> count;
    	 int start=0, end=0;
    	 int minlen=INT_MAX;
    	 int total=0;
    	 for (int i=0; i<t.size(); i++) {
    		 if (count.find(t[i])!=count.end()) {
    			 count[t[i]]++;
    		 } else {
    			 count[t[i]]=1;
    		 }
    	 }

    	 for (int l=0, r=0; r<s.size(); r++) {
    		 if (count.find(s[r])!=count.end()) {
    			 count[s[r]]--;
    			 if (count[s[r]]>=0) total++;

    			 while (total==t.size()) {
    				 if (r-l+1<minlen) {
    					 minlen=r-l+1;
    					 start=l;
    					 end=r;
    				 }

    				 if (count.find(s[l])!=count.end()) {
    					 count[s[l]]++;
    					 if (count[s[l]]>0) total--;
    				 }
    				 l++;
    			 }
    		 }
    	 }

    	 if (minlen==INT_MAX) return "";
    	 else return s.substr(start, end-start+1);
     }
 };

int main()
{
	return 0;
}

