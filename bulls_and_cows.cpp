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
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>

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
      string getHint(string secret, string guess) {
    	  string res;
    	  int bull=0, cow=0;
    	  int size=secret.size();
    	  map<char, int> count;
    	  for (int i=0; i<size; i++) {
    		  if (secret[i]==guess[i]) {
    			  bull++;
    		  } else {
    			  if (count.find(secret[i])==count.end()) {
    				  count[secret[i]]=1;
    			  } else {
    				  count[secret[i]]++;
    			  }
    		  }
    	  }

    	  for (int i=0; i<size; i++) {
    		  if (secret[i]!=guess[i]) {
    			  if (count.find(guess[i])!=count.end()) {
    				  cow++;
    				  count[guess[i]]--;
    				  if (count[guess[i]]==0) count.erase(guess[i]);
    			  }
    		  }
    	  }

    	  char buf[64];
    	  sprintf(buf, "%d", bull);
    	  res.append(buf);
    	  res.append("A");
    	  sprintf(buf, "%d", cow);
    	  res.append(buf);
    	  res.append("B");

    	  return res;
      }
  };

int main()
{
	return 0;
}

