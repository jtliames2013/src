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
	void getCombinationSum3(vector<vector<int>>& res, vector<int>& curr, int k, int n)
	{
		if (n==0 && k==0) {
			res.push_back(curr);
			return;
		} else if (n<0 || k<0) {
			return;
		}

		int start;
		if (curr.size()==0) start=0;
		else start=curr[curr.size()-1];

		for (int i=start+1; i<=9; i++)
		{
			curr.push_back(i);
			getCombinationSum3(res, curr, k-1, n-i);
			curr.pop_back();
		}
	}

    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int> > res;
    	vector<int> curr;

    	getCombinationSum3(res, curr, k, n);

    	return res;
    }
};

int main()
{
	return 0;
}


