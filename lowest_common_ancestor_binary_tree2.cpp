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
	vector<TreeNode*> findPath(TreeNode* root, TreeNode* target) {
		vector<TreeNode*> stk;
		TreeNode* lastVisited=NULL;
		TreeNode* n=root;

		while (!stk.empty() || n!=NULL) {
			if (n!=NULL) {
				stk.push_back(n);
				n=n->left;
			} else {
				TreeNode* peek = stk.back();
				if (peek->right != NULL && lastVisited != peek->right) {
					n=peek->right;
				} else {
					if (peek == target) break;
					lastVisited=stk.back();
					stk.pop_back();
				}
			}
		}

		return stk;
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	vector<TreeNode*> path1=findPath(root, p);
    	vector<TreeNode*> path2=findPath(root, q);

    	TreeNode* prev=NULL;
    	int i=0;
    	while (1) {
    		if (i==path1.size() || i==path2.size()) break;
    		if (path1[i]!=path2[i]) break;
    		prev=path1[i];
    		i++;
    	}

    	return prev;
    }
};

2.
class Solution {
public:
    bool findPath(TreeNode *root, TreeNode *node, vector<TreeNode*>& path) {
        if (root==NULL) return false;
        if (root==node) {
            path.push_back(node);
            return true;
        }
        
        path.push_back(root);
        if (root->left) {
            if (findPath(root->left, node, path)) return true;
        }
        
        if (root->right) {
            if (findPath(root->right, node, path)) return true;
        }
        
        path.pop_back();
        
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        findPath(root, p, path1);
        vector<TreeNode*> path2;
        findPath(root, q, path2);
        
        int i;
        TreeNode *prev=NULL;
        for (i=0; i<path1.size() && i<path2.size(); i++) {
            if (path1[i]!=path2[i]) break;
            prev=path1[i];
        }
        
        return prev;
    }
};

int main()
{
	return 0;
}


