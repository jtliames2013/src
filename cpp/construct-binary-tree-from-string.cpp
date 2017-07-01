536. Construct Binary Tree from String
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   
Note:
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".

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
    TreeNode* str2tree(string s, int start, int& end) {
        int n=s.size();        
        if (start==n) return NULL;
        bool neg=false;
        int i=start;
        if (s[i]=='-') {
            neg=true;
            i++;
        }
        int num=0;
        while (i<n && isdigit(s[i])) {
            num=num*10+s[i]-'0';
            i++;
        }
        num=neg?-num:num;
        
        TreeNode *node=new TreeNode(num);
        end=i;
        if (s[end]=='(') {
            node->left=str2tree(s, end+1, end);
            end++;
        }        
        if (s[end]=='(') {
            node->right=str2tree(s, end+1, end);        
            end++;
        }
        
        return node;
    }
    
    TreeNode* str2tree(string s) {
        int end;        
        return str2tree(s, 0, end);
    }
};

