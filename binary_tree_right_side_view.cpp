#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> res;
    	if (root==NULL) return res;

    	queue<TreeNode*> q1, q2;
    	q1.push(root);

    	while (1) {
    		if (q1.empty() && q2.empty()) break;

    		if (!q1.empty()) {
    			res.push_back(q1.back()->val);
    		}
    		while (!q1.empty()) {
    			TreeNode* n=q1.front();
    			if (n->left) q2.push(n->left);
    			if (n->right) q2.push(n->right);
    			q1.pop();
    		}

    		if (!q2.empty()) {
    			res.push_back(q2.back()->val);
    		}
    		while (!q2.empty()) {
    			TreeNode* n=q2.front();
    			if (n->left) q1.push(n->left);
    			if (n->right) q1.push(n->right);
    			q2.pop();
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}


