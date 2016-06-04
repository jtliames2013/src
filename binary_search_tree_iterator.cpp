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

class BSTIterator {
public:
	stack<TreeNode*> s;

    BSTIterator(TreeNode *root) {
    	TreeNode* curr=root;
    	while (curr!=NULL) {
    		s.push(curr);
    		curr=curr->left;
    	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
    	if (s.empty()) {
    		return false;
    	}

    	return true;
    }

    /** @return the next smallest number */
    int next() {
    	if (!s.empty()) {
    		TreeNode* n=s.top();
    		s.pop();
    		TreeNode* curr=n->right;
			while (curr!=NULL) {
				s.push(curr);
				curr=curr->left;
			}
    		return n->val;
    	} else {
    		return 0;
    	}
    }
};

int main()
{
	return 0;
}


