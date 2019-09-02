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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        stack<TreeNode*> stk;
        unordered_set<TreeNode*> visited;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode *t=stk.top();
            if (t->left && visited.find(t->left)==visited.end()) {
                stk.push(t->left);
            } else if (t->right && visited.find(t->right)==visited.end()) {
                stk.push(t->right);
            } else {
                visited.insert(t);
                res.push_back(t->val);
                stk.pop();
            }
        }
        
        return res;
    }
};

3.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* t=stk.top();
            stk.pop();
            res.push_back(t->val);
            if (t->left) stk.push(t->left);
            if (t->right) stk.push(t->right);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
