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

class Solution {
public:
	void generate(int left, int right, string prefix, vector<string>& res)
	{
		if (left==0 && right==0) {
			res.push_back(prefix);
			return;
		}

		if (left > 0)
		{
			prefix.push_back('(');
			generate(left-1, right, prefix, res);
			prefix.erase(prefix.end()-1);
		}

		if (right > left)
		{
			prefix.push_back(')');
			generate(left, right-1, prefix, res);
			prefix.erase(prefix.end()-1);
		}
	}

    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	if (n==0) return res;

    	generate(n, n, "", res);

    	return res;
    }
};

int main()
{
	return 0;
}

