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
	void GetPath(TreeNode *root, int sum, vector<vector<int> > &res, vector<int> &path)
	{
		if (root == NULL) return;
		path.push_back(root->val);
		sum -= root->val;

		if (root->left == NULL && root->right == NULL)
		{
			if (sum == 0)
			{
				res.push_back(path);
			}
		}
		else
		{
			if (root->left != NULL)
			{
				GetPath(root->left, sum, res, path);
			}

			if (root->right != NULL)
			{
				GetPath(root->right, sum, res, path);
			}
		}

		path.pop_back();
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	vector<vector<int> > res;
    	vector<int> path;
    	GetPath(root, sum, res, path);

    	return res;
    }
};

int main()
{
	return 0;
}

