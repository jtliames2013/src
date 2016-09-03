#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

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

        TreeNode *prev=NULL, *first=NULL, *second=NULL;

        if (root==NULL) return;

        stack<TreeNode*> stk;

        

        TreeNode *n=root;

        while (n!=NULL) {

            stk.push(n);

            n=n->left;

        }

        

        while (!stk.empty()) {

            TreeNode *t=stk.top();

            stk.pop();

            if (prev!=NULL) {

                if (t->val<prev->val) {

                    if (first==NULL) {

                        first=prev;

                        second=t;

                    } else {

                        second=t;

                    }

                }

            }

            prev=t;

            

            n=t->right;

            while (n!=NULL) {

                stk.push(n);

                n=n->left;

            }

        }

        

        if (first && second) {

            int tmp=first->val;

            first->val=second->val;

            second->val=tmp;

        }

    }

};


int main()
{
	return 0;
}

