#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
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

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
    	return generateTreesRange(n, 1, n);
    }

    vector<TreeNode *> generateTreesRange(int n, int start, int end)
	{
    	vector<TreeNode *> res;
    	if (n<=0)
    	{
    		res.push_back(NULL);
    		return res;
    	}

    	if (n==1)
    	{
    		TreeNode *n = new TreeNode(start);
    		res.push_back(n);
    		return res;
    	}

    	for (int i=0; i<n; i++)
    	{
    		vector<TreeNode*> l = generateTreesRange(i, start, start+i-1);
    		vector<TreeNode*> r = generateTreesRange(n-1-i, start+i+1, end);
    		for (unsigned int j=0; j<l.size(); j++)
    		{
    			for (unsigned int k=0; k<r.size(); k++)
    			{
    				TreeNode *n = new TreeNode(start+i);
    				n->left = l[j];
    				n->right = r[k];

    				res.push_back(n);
    			}
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

