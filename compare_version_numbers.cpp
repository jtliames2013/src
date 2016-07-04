note 1.0 equals 1

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
	  bool isZero(string version) {
		  for (int i=0; i<version.size(); i++) {
			  if (version[i]!='.' && version[i]!='0') return false;
		  }

		  return true;
	  }

      int compareVersion(string version1, string version2) {
    	  int idx1, idx2;
    	  while (version1.size()>0 && version2.size()>0) {
    		  string num1;
    		  idx1=version1.find_first_of('.');
    		  if (idx1!=string::npos) {
    			  num1=version1.substr(0,idx1);
    			  version1=version1.substr(idx1+1);
    		  } else {
    			  num1=version1;
    			  version1.clear();
    		  }
    		  string num2;
    		  idx2=version2.find_first_of('.');
    		  if (idx2!=string::npos) {
    			  num2=version2.substr(0,idx2);
    			  version2=version2.substr(idx2+1);
    		  } else {
    			  num2=version2;
    			  version2.clear();
    		  }

    		  int n1=atoi(num1.c_str());
    		  int n2=atoi(num2.c_str());
    		  if (n1>n2) return 1;
    		  else if (n1<n2) return -1;
    	  }

    	  if (version1.size()>0) {
    		  if (isZero(version1)) return 0;
    		  else return 1;
    	  } else if (version2.size()>0) {
    		  if (isZero(version2)) return 0;
    		  else return -1;
    	  } else
    		  return 0;
      }
  };

2.

class Solution {

public:

    int compareVersion(string version1, string version2) {

        int i=0, j=0;

        int val1, val2;

        

        while (i<version1.size() || j<version2.size()) {

            val1=0;

            val2=0;

            

            while (i<version1.size() && version1[i]!='.') {

                val1*=10;

                val1+=version1[i]-'0';

                i++;

            }

            

            while (j<version2.size() && version2[j]!='.') {

                val2*=10;

                val2+=version2[j]-'0';

                j++;

            }

            

            if (val1>val2) return 1;

            else if (val1<val2) return -1;

            

            i++;

            j++;

        }

        

        return 0;

    }

};

int main()
{
	return 0;
}

