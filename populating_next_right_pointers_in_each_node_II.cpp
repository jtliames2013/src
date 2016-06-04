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

int main()
{
	return 0;
}

