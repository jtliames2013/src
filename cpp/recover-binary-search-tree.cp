99. Recover Binary Search Tree
DescriptionHintsSubmissionsSolutions
Total Accepted: 72121
Total Submissions: 244338
Difficulty: Hard
Contributor: LeetCode
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
Subscribe to see which companies asked this question.

Hide Tags Tree Depth-first Search

Morris traversal of binary tree without stack.
http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html

 class Solution {
 public:
     void recoverTree(TreeNode* root) {
         TreeNode *f1=NULL, *f2=NULL;
         TreeNode  *current,*pre, *parent=NULL;

         if(root == NULL)
               return;
         bool found = false;
         current = root;
         while(current != NULL)
         {
               if(current->left == NULL)
               {
                      if(parent && parent->val > current->val)
                      {
                             if(!found)
                             {
                                   f1 = parent;
                                   found = true;
                             }
                             f2 = current;
                      }
                      parent = current;
                      current = current->right;
               }
               else
               {
                      /* Find the inorder predecessor of current */
                      pre = current->left;
                      while(pre->right != NULL && pre->right != current)
                             pre = pre->right;

                      /* Make current as right child of its inorder predecessor */
                      if(pre->right == NULL)
                      {
                             pre->right = current;
                             current = current->left;
                      }

                      /* Revert the changes made in if part to restore the original
                      tree i.e., fix the right child of predecssor */
                      else
                       {
                              pre->right = NULL;
                              if(parent->val > current->val)
                              {
                                    if(!found)
                                    {
                                           f1 = parent;
                                           found = true;
                                    }
                                    f2 = current;
                              }
                              parent = current;
                              current = current->right;
                       } /* End of if condition pre->right == NULL */
                } /* End of if condition current->left == NULL*/
          } /* End of while */

          if(f1 && f2)
                swap(f1->val, f2->val);
     }
 };

2. inorder traversal with stack, O(logn)
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
    void recoverTree(TreeNode* root) {
        if (root==NULL) return;
        stack<TreeNode*> stk;
        TreeNode *first=NULL, *second=NULL, *prev=NULL;
        TreeNode *n=root;
        while (n) {
            stk.push(n);
            n=n->left;
        }
        
        while (!stk.empty()) {
            TreeNode *t=stk.top();
            stk.pop();
            n=t->right;
            
            if (prev && prev->val>t->val) {
                if (first==NULL) {
                    first=prev;
                    second=t;
                } else {
                    second=t;
                }
            }
            prev=t;
            
            while (n) {
                stk.push(n);
                n=n->left;
            }
        }
        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};

