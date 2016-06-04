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
	bool isValid(int row, int col, vector<int>& pos) {
		for (int i=0; i<pos.size(); i++) {
			if (pos[i]==col || abs(row-i)==abs(pos[i]-col)) {
				return false;
			}
		}
		return true;
	}

	void solve(int n, int row, vector<int>& pos, int& res) {
		if (row==n) {
			res++;
			return;
		}

		for (int col=0; col<n; col++) {
			if (isValid(row, col, pos)) {
				pos.push_back(col);
				solve(n, row+1, pos, res);
				pos.pop_back();
			}
		}
	}

    int totalNQueens(int n) {
    	int res=0;
    	vector<int> pos;
    	solve(n, 0, pos, res);

    	return res;
    }
};

int main()
{
	return 0;
}

