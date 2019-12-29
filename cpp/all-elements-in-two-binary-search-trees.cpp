5296. All Elements in Two Binary Search Trees
Medium

10

0

Add to List

Share
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].

Amazon
|
LeetCode

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root!=NULL) {
            TreeNode* n=root;
            while (n) {
                stk.push(n);
                n=n->left;
            }
        }
    } 
    
    int next() {
        if (!hasNext()) return -1;
        auto t=stk.top();
        stk.pop();
        int res=t->val;
        t=t->right;
        while (t) {
            stk.push(t);
            t=t->left;
        }
        return res;
    }
    
    int peek() {
        if (!hasNext()) return -1;
        return stk.top()->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
private:
    stack<TreeNode*> stk;    
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        BSTIterator iter1(root1), iter2(root2);
        while (iter1.hasNext() || iter2.hasNext()) {
            if (iter1.hasNext() && iter2.hasNext()) {
                res.push_back(iter1.peek()<iter2.peek()?iter1.next():iter2.next());
            } else if (iter1.hasNext()) {
                res.push_back(iter1.next());
            } else {
                res.push_back(iter2.next());
            }
        }
        return res;
    }
};

