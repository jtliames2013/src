nclude <stdio.h>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    	vector<vector<int> > res;
    	if (root==NULL) return res;
    	queue<TreeNode*> q1, q2;
    	vector<int> v1, v2;
    	q1.push(root);

    	while (1)
    	{
    		if (q1.empty() && q2.empty()) break;

    		v1.clear();
    		while (!q1.empty())
    		{
    			TreeNode *n = q1.front();
    			q1.pop();
    			v1.push_back(n->val);
    			if (n->left) q2.push(n->left);
    			if (n->right) q2.push(n->right);
    		}
    		if (!v1.empty()) res.push_back(v1);

    		v2.clear();
    		while(!q2.empty())
    		{
    			TreeNode *n = q2.front();
				q2.pop();
				v2.insert(v2.begin(), n->val);
				if (n->left) q1.push(n->left);
				if (n->right) q1.push(n->right);
    		}
    		if (!v2.empty()) res.push_back(v2);
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

