#include <stdio.h>
#include <vector>
#include <queue>

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

