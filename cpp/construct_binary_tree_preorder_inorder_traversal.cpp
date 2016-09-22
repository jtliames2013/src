105. Construct Binary Tree from Preorder and Inorder Traversal  QuestionEditorial Solution  My Submissions
Total Accepted: 72257 Total Submissions: 243466 Difficulty: Medium
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Subscribe to see which companies asked this question

Hide Tags Tree Array Depth-first Search
Hide Similar Problems (M) Construct Binary Tree from Inorder and Postorder Traversal

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

	TreeNode *buildTreeRange(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend)
	{
		if (instart > inend) return NULL;

		int pos=findPos(preorder[prestart], inorder);

		TreeNode *n = new TreeNode(preorder[prestart]);
		n->left = buildTreeRange(preorder, prestart+1, prestart+1+(pos-1-instart), inorder, instart, pos-1);
		n->right= buildTreeRange(preorder, prestart+1+(pos-1-instart)+1, preend, inorder, pos+1, inend);

		return n;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int prelen=preorder.size();
		int inlen=inorder.size();
		if (prelen==0 || inlen==0) return NULL;

		return buildTreeRange(preorder, 0, prelen-1, inorder, 0, inlen-1);
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
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart>preEnd) return NULL;
        TreeNode* node=new TreeNode(preorder[preStart]);
        int index=pos[preorder[preStart]];
        node->left=buildTree(preorder, preStart+1, preStart+(index-inStart), inorder, inStart, index-1);
        node->right=buildTree(preorder, preStart+(index-inStart)+1, preEnd, inorder, index+1, inEnd);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0) return NULL;
        for (int i=0; i<inorder.size(); i++) pos[inorder[i]]=i;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    map<int,int> pos;
};

int main()
{
	return 0;
}

