872. Leaf-Similar Trees
DescriptionHintsSubmissionsDiscussSolution
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.

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
    class LeafIterator {
    public:
        LeafIterator(TreeNode* root) {
            if (root) {
                stk.push(root);
            }            
        }
        
        TreeNode* next() {
            if (!hasNext()) return NULL;
            while (true) {
                TreeNode *n=stk.top();
                stk.pop();
                if (n->left==NULL && n->right==NULL) return n;
                if (n->right) stk.push(n->right);
                if (n->left) stk.push(n->left);                
            }    
        }
        
        bool hasNext() {
            return !stk.empty();
        }
    private:
        stack<TreeNode*> stk;
    };
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        LeafIterator iter1(root1), iter2(root2);
        while (iter1.hasNext() && iter2.hasNext()) {
            if (iter1.next()->val!=iter2.next()->val) return false;
        }
        return !iter1.hasNext() && !iter2.hasNext();
    }
};
