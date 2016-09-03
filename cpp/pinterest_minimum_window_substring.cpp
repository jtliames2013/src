76. Minimum Window Substring  
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Hide Company Tags LinkedIn Uber Facebook
Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Substring with Concatenation of All Words (M) Minimum Size Subarray Sum (H) Sliding Window Maximum

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

2. No need to set map element to 1. just ++ is fine.
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        for (int i=0; i<t.size(); i++) {
            count[t[i]]++;
        }
        int total=0, start, end, minLen=INT_MAX;
        
        for (int l=0, r=0; r<s.size(); r++) {
            if (count.find(s[r])!=count.end()) {
                if (count[s[r]]>0) total++;
                count[s[r]]--;
            }
            
            while (total==t.size()) {
                if (minLen>r-l+1) {
                    start=l;
                    end=r;
                    minLen=r-l+1;
                }
                
                if (count.find(s[l])!=count.end()) {
                    count[s[l]]++;
                    if (count[s[l]]>0) total--;
                }
                l++;
            }
        }
        
        if (minLen==INT_MAX) return "";
        else return s.substr(start, end-start+1);
    }
};

3. Simplified version. Use set of char as input
  class Solution {
  public:
      string minWindow(string s, set<char> st) {
    	  map<char, int> count;
    	  for (auto c:st) count[c]++;
    	  int total;
    	  int maxLen=INT_MIN;
    	  int start, end;

    	  for (int l=0, r=0; r<s.size(); r++) {
    		  if (count.find(s[r])!=count.end()) {
    			  if (count[s[r]]>0) total++;
    			  count[s[r]]--;

    			  while (total==st.size()) {
    				  if (r-l+1>maxLen) {
    					  maxLen=r-l+1;
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

    	  if (maxLen==INT_MIN) return "";
    	  else return s.substr(start, end-start+1);
      }
  };

int main()
{
	return 0;
}

