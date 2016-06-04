ending condition: no left and no right. assueme root is not NULL. 

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
	  string getPathStr(vector<string> path) {
		  string res;
		  for (int i=0; i<path.size(); i++) {
			  res.append(path[i]);
			  if (i<path.size()-1) res.append("->");
		  }
		  return res;
	  }

	  void getTreePaths(TreeNode* root, vector<string>& res, vector<string>& path) {
		  char buf[64];
		  sprintf(buf, "%d", root->val);
		  path.push_back(buf);

		  if (root->left==NULL && root->right==NULL) {
			  string str=getPathStr(path);
			  res.push_back(str);

			  path.pop_back();
			  return;
		  }

		  if (root->left) {
			  getTreePaths(root->left, res, path);
		  }

		  if (root->right) {
			  getTreePaths(root->right, res, path);
		  }

		  path.pop_back();
	  }

      vector<string> binaryTreePaths(TreeNode* root) {
    	  vector<string> res;
    	  vector<string> path;
    	  if (root==NULL) return res;
    	  getTreePaths(root, res, path);

    	  return res;
      }
  };

int main()
{
	return 0;
}

