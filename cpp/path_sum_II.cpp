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
	vector<int> makeIntPath(vector<TreeNode*> p)
	{
		vector<int> res;
		while (!p.empty())
		{
			res.insert(res.begin(), p.back()->val);
			p.pop_back();
		}
		return res;
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	vector<vector<int> > res;
    	vector<TreeNode*> path;
    	int s=0;
    	if (root==NULL) return res;

    	TreeNode *tmp = root;
    	while (tmp != NULL)
    	{
    		path.push_back(tmp);
    		s += tmp->val;
    		tmp = tmp->left;
    	}

    	while (!path.empty())
    	{
    		TreeNode* n = path.back();
    		if (n->left==NULL && n->right==NULL)
    		{
    			if (s==sum)
    			{
    				res.push_back(makeIntPath(path));
    			}

    			s -= n->val;
    			n->val = 0x80000000;
    			path.pop_back();
    		}
    		else if (n->right != NULL && n->right->val != 0x80000000)
    		{
    			tmp = n->right;
    			while (tmp != NULL)
    			{
    				path.push_back((tmp));
    				s += tmp->val;
    				tmp = tmp->left;
    			}
    		}
    		else
    		{
    			s -= n->val;
    			n->val = 0x80000000;
    			path.pop_back();
    		}
    	}
    }
};

int main()
{
	return 0;
}

