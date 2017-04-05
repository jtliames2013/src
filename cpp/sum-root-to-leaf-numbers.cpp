129. Sum Root to Leaf Numbers  QuestionEditorial Solution  My Submissions
Total Accepted: 87140 Total Submissions: 256129 Difficulty: Medium
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Subscribe to see which companies asked this question

Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Path Sum (H) Binary Tree Maximum Path Sum

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
    int getNum(vector<int>& path) {
        int num=0;
        for (auto p:path) {
            num*=10;
            num+=p;
        }
        return num;
    }
    
    void getSum(int& sum, vector<int>& path, TreeNode* root) {
        if (root==NULL) return;
        path.push_back(root->val);
        if (root->left==NULL&&root->right==NULL) {
            sum+=getNum(path);
            path.pop_back();
            return;
        } 
        
        if (root->left) {
            getSum(sum, path, root->left);
        }

        if (root->right) {
            getSum(sum, path, root->right);
        }
        
        path.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        int sum=0;
        vector<int> path;
        getSum(sum, path, root);
        
        return sum;
    }
};

