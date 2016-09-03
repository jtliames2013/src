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
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > res;

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
    			v.push_back(t->val);
    			if (t->left) q2.push(t->left);
    			if (t->right) q2.push(t->right);
    		}
    		if (!v.empty())
    		{
    			res.push_back(v);
    			v.clear();
    		}

    		while (!q2.empty())
			{
				TreeNode* &t = q2.front();
				q2.pop();
				v.push_back(t->val);
				if (t->left) q1.push(t->left);
				if (t->right) q1.push(t->right);
			}
			if (!v.empty())
			{
				res.push_back(v);
				v.clear();
			}
    	}

    	return res;
    }
};

2. use one queue and count level

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

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (root==NULL) return res;

        queue<TreeNode*> q;

        int currlevel=0, nextlevel=0;

        vector<int> level;

        q.push(root);

        currlevel++;

        

        while (!q.empty()) {

            TreeNode* t=q.front();

            q.pop();

            currlevel--;

            level.push_back(t->val);

            

            if (t->left) {

                q.push(t->left);

                nextlevel++;

            }

            if (t->right) {

                q.push(t->right);

                nextlevel++;

            }

            

            if (currlevel==0) {

                currlevel=nextlevel;

                nextlevel=0;

                res.push_back(level);

                level.clear();

            }

        }

        

        return res;

    }

};


int main()
{
	return 0;
}

