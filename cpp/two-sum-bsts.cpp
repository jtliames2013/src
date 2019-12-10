1214. Two Sum BSTs
Medium

76

6

Favorite

Share
Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

 

Example 1:



Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.
Example 2:



Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false
 

Constraints:

Each tree has at most 5000 nodes.
-10^9 <= target, node.val <= 10^9

Amazon
|
3

1. two pointers
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        stack<TreeNode*> stk1, stk2;
        TreeNode *n1=root1, *n2=root2;
        while (n1) {
            stk1.push(n1);
            n1=n1->left;
        }
        while (n2) {
            stk2.push(n2);
            n2=n2->right;
        }
        
        while (!stk1.empty() && !stk2.empty()) {
            n1=stk1.top();            
            n2=stk2.top();            
            int sum=n1->val+n2->val;            
            if (sum==target) return true;
            else if (sum<target) {
                stk1.pop();
                n1=n1->right;
                while (n1) {
                    stk1.push(n1);
                    n1=n1->left;
                }
            } else {
                stk2.pop();
                n2=n2->left;
                while (n2) {
                    stk2.push(n2);
                    n2=n2->right;
                }
            }
        }
        return false;
    }
};

2. hash set
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> st;
        stack<TreeNode*> stk;
        TreeNode* n=root2;
        while (n) {
            stk.push(n);
            n=n->left;            
        }
        while (!stk.empty()) {
            n=stk.top();
            st.insert(n->val);
            stk.pop();
            n=n->right;
            while (n) {
                stk.push(n);
                n=n->left;
            }
        }
        
        n=root1;
        while (n) {
            stk.push(n);
            n=n->left;
        }
        while (!stk.empty()) {
            n=stk.top();
            if (st.find(target-n->val)!=st.end()) return true;
            stk.pop();
            n=n->right;
            while (n) {
                stk.push(n);
                n=n->left;
            }
        }
        return false;
    }
};
