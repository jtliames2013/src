230. Kth Smallest Element in a BST  QuestionEditorial Solution  My Submissions
Total Accepted: 58306 Total Submissions: 147374 Difficulty: Medium
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Company Tags Bloomberg Uber Google
Hide Tags Binary Search Tree
Hide Similar Problems (M) Binary Tree Inorder Traversal


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	if (root==NULL) return 0;
    	stack<TreeNode *>stk;

    	TreeNode* n=root;
    	while (n!=NULL) {
    		stk.push(n);
    		n=n->left;
    	}

    	while (!stk.empty()) {
    		TreeNode* node = stk.top();
    		k--;
    		if (k==0) {
    			return node->val;
    		}

    		stk.pop();
    		TreeNode* r=node->right;
    		while (r!=NULL) {
    			stk.push(r);
    			r=r->left;
    		}
    	}
    }
};

一步思考：
如果BST节点TreeNode的属性可以扩展，则再添加一个属性leftCnt，记录左子树的节点个数

记当前节点为node

当node不为空时循环：

若k == node.leftCnt + 1：则返回node

否则，若k > node.leftCnt：则令k -= node.leftCnt + 1，令node = node.right

否则，node = node.left
上述算法时间复杂度为O(BST的高度)

int main()
{
	return 0;
}

