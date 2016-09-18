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

2.
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int currLevel=1, nextLevel=0;
        vector<int> level;
        
        while (!q.empty()) {
            TreeNode *f=q.front();
            q.pop();
            level.push_back(f->val);
            currLevel--;
            
            if (f->left) {
                q.push(f->left);
                nextLevel++;
            }
            if (f->right) {
                q.push(f->right);
                nextLevel++;
            }
            
            if (currLevel==0) {
                res.push_back(level);
                level.clear();
                currLevel=nextLevel;
                nextLevel=0;
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

int main()
{
	return 0;
}

