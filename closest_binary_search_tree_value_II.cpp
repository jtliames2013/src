// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  class Solution {
public:
    long long getPredecessor(stack<TreeNode*>& small) {
        if(!small.empty()) {
            TreeNode *n=small.top();
            small.pop();
            TreeNode *node=n->left;
            while (node!=NULL) {
                small.push(node);
                node=node->right;
            }
            return n->val;
        } else {
            return LLONG_MIN;
        }
    }

    long long getSuccessor(stack<TreeNode*>& large) {
        if (!large.empty()) {
            TreeNode *n=large.top();
            large.pop();
            TreeNode *node=n->right;
            while (node!=NULL) {
                large.push(node);
                node=node->left;
            }
            return n->val;
        } else {
            return LLONG_MAX;
        }
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> small, large;
        while (root!=NULL) {
            if (root->val>target) {
                large.push(root);
                root=root->left;
            } else {
                small.push(root);
                root=root->right;
            }
        }

        long long s, l;
        s=getPredecessor(small);
        l=getSuccessor(large);

        for (int i=0; i<k; i++) {
            if (abs(target-s)<abs(l-target)) {
                res.push_back(s);
                s=getPredecessor(small);
            } else {
                res.push_back(l);
                l=getSuccessor(large);
            }
        }

        return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
