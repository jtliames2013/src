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
    vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> res;
    	stack<TreeNode*> stk;
    	if (root==NULL) return res;

    	TreeNode *n=root;
    	while (n!=NULL)
    	{
    		stk.push(n);
    		n=n->left;
    	}

    	while (!stk.empty())
    	{
    		TreeNode *tmp = stk.top();
    		stk.pop();
    		res.push_back(tmp->val);

    		TreeNode *n=tmp->right;
			while (n!=NULL)
			{
				stk.push(n);
				n=n->left;
			}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

