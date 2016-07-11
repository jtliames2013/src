333. Largest BST Subtree
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Hint:

You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?

Hide Company Tags Microsoft
Hide Tags Tree

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

// NOTE: a subtree can be BST but the parent tree doesn't need to be. So need to use INT_MAX and INT_MIN from any node 
// but return max and min to determine if parent is BST.

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    struct Element {
        int count;
        bool isBST;
        int minVal;
        int maxVal;
        Element() : count(0), isBST(false), minVal(INT_MAX), maxVal(INT_MIN) {}
        Element(int c, bool b, int mi, int mx) : count(c), isBST(b), minVal(mi), maxVal(mx) {}
    };

    Element getLargest(TreeNode* root, int lower, int upper) {
        // NULL node has lower as INT_MAX and upper as INT_MIN  so that a single node can have the right min and max.
        if (root==NULL) return Element(0, true, INT_MAX, INT_MIN);
        Element res;
        Element left=getLargest(root->left, INT_MIN, INT_MAX);
        Element right=getLargest(root->right, INT_MIN, INT_MAX);
        if (left.isBST && right.isBST && left.maxVal<root->val && right.minVal>root->val) {
            res.isBST=true;
        }
        if (res.isBST==true) {
            res.count=left.count+right.count+1;
            res.minVal=min(left.minVal, root->val);
            res.maxVal=max(right.maxVal, root->val);
        } else {
            res.count=max(left.count, right.count);
        }
        return res;
    }

    int largestBSTSubtree(TreeNode* root) {
        Element res=getLargest(root, INT_MIN, INT_MAX);
        return res.count;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    Solution s;
    TreeNode *n=new TreeNode(1);
    s.largestBSTSubtree(n);
	return 0;
}
