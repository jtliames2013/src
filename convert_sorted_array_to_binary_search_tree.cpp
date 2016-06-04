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
	TreeNode *sortedArrayToBSTRange(vector<int> &num, int start, int end)
	{
		if (start > end) return NULL;

		int mid = start + (end-start)/2;
		TreeNode *n = new TreeNode(num[mid]);
		n->left = sortedArrayToBSTRange(num, start, mid-1);
		n->right = sortedArrayToBSTRange(num, mid+1, end);
		return n;
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
    	if (num.size() == 0) return NULL;
    	return sortedArrayToBSTRange(num, 0, num.size()-1);
    }
};

int main()
{
	return 0;
}

