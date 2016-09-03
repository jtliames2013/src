#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>

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

class Solution {
public:
	void preTraversalRecur(TreeNode *root, vector<int> &v)
	{
		if (root == NULL) return;
		v.push_back(root->val);

		preTraversalRecur(root->left, v);
		preTraversalRecur(root->right, v);
	}

	void preTraversalIter(TreeNode *root, vector<int> &v)
	{
		if (root == NULL) return;

		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty())
		{
			TreeNode *t = s.top();
			v.push_back(t->val);
			s.pop();
			if (t->right != NULL)
			{
				s.push(t->right);
			}
			if (t->left != NULL)
			{
				s.push(t->left);
			}
		}
	}

    vector<int> preorderTraversal(TreeNode *root) {
    	vector<int> res;

    	preTraversalRecur(root, res);
    	//preTraversalIter(root, res);

    	return res;
    }
};

int main()
{
	return 0;
}

