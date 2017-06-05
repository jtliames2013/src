606. Construct String from Binary Tree
DescriptionHintsSubmissionsSolutions
Total Accepted: 2004
Total Submissions: 3617
Difficulty: Easy
Contributors:
love_Fawn
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
Subscribe to see which companies asked this question.

Hide Tags Tree String
Hide Similar Problems (M) Construct Binary Tree from String

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
    void dfs(string& res, TreeNode* t) {
        if (t==NULL) return;
        res+=to_string(t->val);
        if (t->left || (t->left==NULL && t->right)) {
            res+="(";
            dfs(res, t->left);
            res+=")";
        }
        if (t->right) {
            res+="(";
            dfs(res, t->right);
            res+=")";
        }
    }
    string tree2str(TreeNode* t) {
        string res;
        dfs(res, t);
        return res;
    }
};

