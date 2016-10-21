222. Count Complete Tree Nodes  QuestionEditorial Solution  My Submissions
Total Accepted: 38077 Total Submissions: 146866 Difficulty: Medium
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Hide Tags Tree Binary Search
Show Similar Problems

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
    int countNodes(TreeNode* root) {
    	if (root==NULL) return 0;
    	int ldepth=0, rdepth=0;
    	TreeNode *n=root;
    	while (n) {
    		ldepth++;
    		n=n->left;
    	}
    	n=root;
    	while (n) {
    		rdepth++;
    		n=n->right;
    	}
    	if (ldepth==rdepth) {
    		return (1<<ldepth)-1;
    	} else {
    		return 1 + countNodes(root->left) + countNodes(root->right);
    	}

    }
};

2.
class Solution {
public:
    int countNodes(TreeNode* root) {
        int res=0;
        while (root!=NULL) {
            int lcount=0, rcount=0;
            for(TreeNode *n=root->left; n!=NULL; n=n->left) lcount++;
            for(TreeNode *n=root->right; n!=NULL; n=n->left) rcount++;
            if (lcount==rcount) {
                res+=(1<<lcount);
                root=root->right;
            } else {
                res+=(1<<rcount);
                root=root->left;
            }
        }
        return res;
    }
};

int main()
{
	return 0;
}

