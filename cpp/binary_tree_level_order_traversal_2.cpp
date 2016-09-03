#include <stdio.h>
#include <vector>
#include <queue>

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

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	vector<vector<int> > res;
    	vector<vector<int> > temp;

    	if (root == NULL) return res;

    	queue<TreeNode*> q1, q2;
    	q1.push(root);

    	vector<int> v;
    	while (1)
    	{
    		if (q1.empty() && q2.empty()) break;

			while (!q1.empty())
			{
				TreeNode* &t = q1.front();
				q1.pop();
				if (t->left) { q2.push(t->left); }
				if (t->right) { q2.push(t->right); }
				v.push_back(t->val);
			}
			if (!v.empty())
			{
				temp.push_back(v);
				v.clear();
			}

			while (!q2.empty())
			{
				TreeNode* &t = q2.front();
				q2.pop();
				if (t->left) { q1.push(t->left); }
				if (t->right) { q1.push(t->right); }
				v.push_back(t->val);
			}
			if (!v.empty())
			{
				temp.push_back(v);
				v.clear();
			}
    	}

    	while (!temp.empty())
    	{
    		res.push_back(temp.back());
    		temp.pop_back();
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

