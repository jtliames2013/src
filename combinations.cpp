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
	void getCombine(vector<vector<int> > &res, vector<int> &v, int n, int index, int k)
	{
		if (k==0) {
			res.push_back(v);
			return;
		}

		for (int i=index; i<=n-k; i++) {
			v.push_back(i+1);
			getCombine(res, v, n, i+1, k-1);
			v.pop_back();
		}
	}

    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int> > res;
    	vector<int> v;
    	if (k==0) return res;

    	getCombine(res, v, n, 0, k);

    	return res;
    }
};

int main()
{
	return 0;
}

