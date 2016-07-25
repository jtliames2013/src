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

Largest BST Subtree  struct TreeNode {
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
			// for NULL node case, use min() and max();
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

题目中的Follow up让我们用O(n)的时间复杂度来解决问题，我们还是采用DFS的思想来解题，由于时间复杂度的限制，只允许我们遍历一次整个二叉树，由于满足题目要求的 二叉搜索子树必定是有叶节点的，所以我们的思路就是先递归到最左子节点，然后逐层往上递归，对于每一个节点，我们都记录当前最大的BST的节点数，当做为左子树的最大值，和做为右子树的最小值，当每次遇到左子节点不存在或者当前节点值大于左子树的最大值，且右子树不存在或者当前节点值小于右子树的最小数时，说明BST的节点数又增加了一个，我们更新结果及其参数，如果当前节点不是BST的节点，那么我们更新BST的节点数res为左右子节点的各自的BST的节点数的较大值，参见代码如下：

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0, mn = INT_MIN, mx = INT_MAX;
        bool d = isValidBST(root, mn, mx, res);
        return res;
    }
    bool isValidBST(TreeNode *root, int &mn, int &mx, int &res) {
        if (!root) return true;
        int left_n = 0, right_n = 0, left_mn = INT_MIN;
        int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
        bool left = isValidBST(root->left, left_mn, left_mx, left_n);
        bool right = isValidBST(root->right, right_mn, right_mx, right_n);
        if (left && right) {
            if ((!root->left || root->val >= left_mx) && (!root->right || root->val <= right_mn)) {
                res = left_n + right_n + 1;
                mn = root->left ? left_mn : root->val;
                mx = root->right ? right_mx : root->val;
                return true;
            }
        }
        res = max(left_n, right_n);
        return false;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    Solution s;
    TreeNode *n=new TreeNode(1);
    s.largestBSTSubtree(n);
	return 0;
}
