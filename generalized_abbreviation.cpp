Write a function to generate the generalized abbreviations of a word.

Example:

Given word = "word", return the following list (order does not matter):

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


NOTE: use recursion. avoid duplicate. letter and number are interleaved in the pattern.

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
#include <unordered_map>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

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
	  void getAbbr(vector<string>& res, string& word, int idx, string& abbr, bool prevIsNum) {
		  if (idx==word.size()) {
			  res.push_back(abbr);
			  return;
		  }

		  for (int i=idx; i<word.size(); i++) {
			  int pos=abbr.size();
			  if (prevIsNum) {
				  abbr += word.substr(idx, i-idx+1);
				  getAbbr(res, word, i+1, abbr, false);
				  abbr.erase(pos);
			  } else {
				  abbr += to_string(i-idx+1);
				  getAbbr(res, word, i+1, abbr, true);
				  abbr.erase(pos);
			  }
		  }
	  }

      vector<string> generateAbbreviations(string word) {
    	  vector<string> res;
    	  if (word.size()==0) {
    		  res.push_back(word);
    		  return res;
    	  }

    	  string abbr;
    	  getAbbr(res, word, 0, abbr, false);
    	  getAbbr(res, word, 0, abbr, true);
    	  return res;
      }
  };

int main()
{
	return 0;
}

