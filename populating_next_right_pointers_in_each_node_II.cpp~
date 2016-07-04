117. Populating Next Right Pointers in Each Node II 
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
Hide Company Tags Microsoft Bloomberg Facebook
Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Populating Next Right Pointers in Each Node

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

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

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	queue<TreeLinkNode*> q1;
    	queue<TreeLinkNode*> q2;

    	if (root==NULL) return;

    	q1.push(root);

    	while(1)
    	{
    		if (q1.empty() && q2.empty()) break;

    		TreeLinkNode* prev=NULL;
    		while (!q1.empty())
    		{
    			TreeLinkNode* node=q1.front();
    			q1.pop();

    			if (prev != NULL)
    			{
    				prev->next = node;
    			}
    			prev=node;

    			if (node->left != NULL) q2.push(node->left);
    			if (node->right != NULL) q2.push(node->right);
    		}

    		prev=NULL;
			while (!q2.empty())
			{
				TreeLinkNode* node=q2.front();
				q2.pop();

				if (prev != NULL)
				{
					prev->next = node;
				}
				prev=node;

				if (node->left != NULL) q1.push(node->left);
				if (node->right != NULL) q1.push(node->right);
			}
    	}
    }
};

2. Do right recursive first. Use loop to find the first non-NULL next.

class Solution {

public:

    void connect(TreeLinkNode *root) {

        if (root==nullptr) return; 

        

        if (root->left) {

            if (root->right) root->left->next=root->right;

            else {

                TreeLinkNode *curr=root->next;

                while (curr!=NULL) {

                    if (curr->left) {

                        root->left->next=curr->left;

                        break;

                    } else if (curr->right) {

                        root->left->next=curr->right;

                        break;

                    }

                    

                    curr=curr->next;

                }

            }

        }

        

        if (root->right) {

            TreeLinkNode *curr=root->next;

            while (curr!=NULL) {

                if (curr->left) {

                    root->right->next=curr->left;

                    break;

                } else if (curr->right) {

                    root->right->next=curr->right;

                    break;

                }

                

                curr=curr->next;

            }

        }

        connect(root->right);

        connect(root->left);

    }

};

int main()
{
	return 0;
}

