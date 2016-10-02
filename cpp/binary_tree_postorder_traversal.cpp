145. Binary Tree Postorder Traversal  QuestionEditorial Solution  My Submissions
Total Accepted: 113879 Total Submissions: 305132 Difficulty: Hard
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

Subscribe to see which companies asked this question

Hide Tags Tree Stack
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
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> stk;
    	TreeNode* lastVisited=NULL;
    	TreeNode* n=root;

    	while (!stk.empty() || n!=NULL) {
    		if (n!=NULL) {
    			stk.push(n);
    			n=n->left;
    		} else {
    			TreeNode* peek = stk.top();
    			if (peek->right!=NULL && peek->right!=lastVisited) {
    				n=peek->right;
    			} else {
    				res.push_back(peek->val);
    				lastVisited=peek;
    				stk.pop();
    			}
    		}
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root==NULL) return res;
        set<TreeNode*> visited;
        stk.push(root);
        visited.insert(root);
        
        while (!stk.empty()) {
            TreeNode* n=stk.top();
            if (n->left && visited.find(n->left)==visited.end()) {
                stk.push(n->left);
                visited.insert(n->left);
            } else if (n->right && visited.find(n->right)==visited.end()) {
                stk.push(n->right);
                visited.insert(n->right);
            } else {
                res.push_back(stk.top()->val);
                stk.pop();
            }
        }
        
        return res;
    }
};

int main()
{
	return 0;
}


