129. Sum Root to Leaf Numbers  QuestionEditorial Solution  My Submissions
Total Accepted: 87140 Total Submissions: 256129 Difficulty: Medium
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Subscribe to see which companies asked this question

Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Path Sum (H) Binary Tree Maximum Path Sum

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

class Solution {
public:
	unsigned long long convertToInteger(vector<int> &n)
	{
		unsigned long long res = 0;

		for (int i=0; i<n.size(); i++)
		{
			res *= 10;
			res += n[i];
		}

		return res;
	}

    int sumNumbers(TreeNode *root) {
    	vector<int> num;
    	vector<TreeNode*> st;
    	unsigned long long sum = 0;
    	if (root == NULL) return 0;

    	num.push_back(root->val);
    	st.push_back(root);

    	while (!st.empty())
    	{
    		TreeNode* node = st.back();
    		node->val = 10; //visited
    		if (node->left != NULL && node->left->val < 10)
    		{
    			st.push_back(node->left);
    			num.push_back(node->left->val);
    		}
    		else if (node->right != NULL && node->right->val < 10)
    		{
    			st.push_back(node->right);
    			num.push_back(node->right->val);
    		}
    		else
    		{
    			if (node->left == NULL && node->right == NULL)
    			{
    				sum += convertToInteger(num);
    			}

    			st.pop_back();
    			num.pop_back();
    		}
    	}

    	return sum;
    }
};

int main()
{
	return 0;
}

