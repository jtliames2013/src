106. Construct Binary Tree from Inorder and Postorder Traversal QuestionEditorial Solution  My Submissions
Total Accepted: 62571 Total Submissions: 208998 Difficulty: Medium
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Subscribe to see which companies asked this question

Hide Tags Tree Array Depth-first Search
Hide Similar Problems (M) Construct Binary Tree from Preorder and Inorder Traversal

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

class Solution {
public:
	int findPos(int val, vector<int> &order)
	{
		int i=0;
		int len = order.size();
		for (i=0; i<len; i++)
		{
			if (order[i]==val) return i;
		}
		return i;
	}

	TreeNode *buildTreeRange(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend)
	{
		if (instart > inend) return NULL;

		int pos=findPos(postorder[postend], inorder);

		TreeNode *n = new TreeNode(postorder[postend]);
		n->left = buildTreeRange(inorder, instart, pos-1, postorder, poststart, poststart + (pos-1-instart));
		n->right= buildTreeRange(inorder, pos+1, inend, postorder, poststart + (pos-1-instart) + 1, postend-1);

		return n;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int inlen=inorder.size();
		int postlen=postorder.size();
		if (inlen==0 || postlen==0) return NULL;

		return buildTreeRange(inorder, 0, inlen-1, postorder, 0, postlen-1);
    }
};

2. Use hash table instead of find index
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
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart>inEnd) return NULL;
        TreeNode* node=new TreeNode(postorder[postEnd]);
        int index=pos[postorder[postEnd]];
        node->left=buildTree(inorder, inStart, index-1, postorder, postStart, postStart+(index-inStart-1));
        node->right=buildTree(inorder, index+1, inEnd, postorder, postStart+(index-inStart), postEnd-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0) return NULL;
        for (int i=0; i<inorder.size(); i++) {
            pos[inorder[i]]=i;
        }
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
private:
    unordered_map<int,int> pos;
};

int main()
{
	return 0;
}

