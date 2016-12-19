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

class Solution {
public:
    string getStr(vector<int>& path) {
        string res;
        for (int i=0; i<path.size(); i++) {
            if (i>0) res+="->";
            res+=to_string(path[i]);
        }
        return res;
    }
    void getPath(vector<string>& res, vector<int>& path, TreeNode* root) {
        if (root==NULL) return;
        path.push_back(root->val);
        if (root->left==NULL&&root->right==NULL) {
            res.push_back(getStr(path));
            path.pop_back();
            return;
        }
        
        getPath(res, path, root->left);
        getPath(res, path, root->right);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        getPath(res, path, root);
        return res;
    }
};

2. iteratively
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

