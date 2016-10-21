114. Flatten Binary Tree to Linked List  
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

Hide Company Tags Microsoft
Hide Tags Tree Depth-first Search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

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

1. At each node level, process its children

class Solution {
public:
	TreeNode* traversal(TreeNode* node)
	{
		TreeNode* last=NULL;
		if (node==NULL) return last;
		if (node->left==NULL && node->right==NULL) return node;
		else if (node->left==NULL)
		{
			return traversal(node->right);
		}
		else if (node->right==NULL)
		{
			node->right = node->left;
			node->left=NULL;
			return traversal(node->right);
		}
		else
		{
			TreeNode* l=traversal(node->left);
			TreeNode* r=traversal(node->right);
			l->right=node->right;
			node->right=node->left;
			node->left=NULL;
			return r;
		}
	}

    void flatten(TreeNode *root) {
    	if (root==NULL) return;

    	traversal(root);
    }
};

2. At each node level, pass a parent down so that no need to handle children

class Solution {
public:
    void getFlat(TreeNode* node, TreeNode* prev, TreeNode** last) {
        if (node==NULL) return;
        if (prev) prev->right=node;
        *last=node;
        TreeNode *r=node->right;
        if (node->left) {
            getFlat(node->left, node, last);
            node->left=NULL;
        }
        
        if (r) {
            getFlat(r, *last, last);
        }
    }
   
    void flatten(TreeNode* root) {
        TreeNode** last=&root;
        getFlat(root, NULL, last);
    }
};

3.
class Solution {
public:
    TreeNode* flatten(TreeNode *root, TreeNode *parent) {
        if (root==NULL) return NULL;
        TreeNode *last=root;
        if (parent!=NULL) parent->right=root;
        TreeNode *r=root->right;
        if (root->left) {
            last=flatten(root->left, root);
            root->left=NULL;
        }
        if (r) {
            last=flatten(r, last);
        }
        
        return last;
    }
    
    void flatten(TreeNode* root) {
        flatten(root, NULL);
    }
};

int main()
{
	return 0;
}

