257. Binary Tree Paths 
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Company Tags Google Apple Facebook
Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Path Sum II

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

2. use int vector
class Solution {
public:
    string convert(vector<int>& path) {
        string str;
        for (int i=0; i<path.size(); i++) {
            if (i>0) {
                str+="->";
            }
            str+=to_string(path[i]);
        }
        return str;
    }
    
    void findPaths(TreeNode* root, vector<string>& res, vector<int>& path) {
        if (root==NULL) return;
        
        if (root->left==NULL && root->right==NULL) {
            path.push_back(root->val);
            res.push_back(convert(path));
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);    
        if (root->left) findPaths(root->left, res, path);
        if (root->right) findPaths(root->right, res, path);
        path.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        findPaths(root, res, path);
        
        return res;
    }
};

3. iteratively
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string getString(vector<TreeNode*> v) {
        string res;
        for (int i=0; i<v.size(); i++) {
            if (i>0) {
                res+="->";
            }
            res+=to_string(v[i]->val);
        }    
        return res;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<TreeNode*> path;
        set<TreeNode*> visited;
        vector<string> res;
        if (root==NULL) return res;
        path.push_back(root);
        visited.insert(root);
        while (!path.empty()) {
            if (path.back()->left && visited.find(path.back()->left)==visited.end()) {
                visited.insert(path.back()->left);
                path.push_back(path.back()->left);
            } else if (path.back()->right && visited.find(path.back()->right)==visited.end()) {
                visited.insert(path.back()->right);
                path.push_back(path.back()->right);
            } else {
                if (path.back()->left==NULL && path.back()->right==NULL) {
                    res.push_back(getString(path));
                }
                path.pop_back();
            }
        }
        
        return res;
    }
};

int main()
{
	return 0;
}

