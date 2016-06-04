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
	vector<int> getGrayCode(int n) {
		if (n == 0) {
			vector<int> res;
			res.push_back(0);
			return res;
		}

		if (n == 1) {
			vector<int> res;
			res.push_back(0);
			res.push_back(1);
			return res;
		}

		vector<int> res1 = getGrayCode(n-1);
		vector<int> res2 = getGrayCode(n-1);

		int size=res2.size();
		int num = (1 << (n-1));
		for (int i=0; i<size; i++) {
			res1.push_back(res2[size-1-i] | num);
		}

		return res1;
	}

	vector<int> grayCode(int n) {
		vector<int> res;

		res = getGrayCode(n);

		return res;
    }
};

int main()
{
	return 0;
}

