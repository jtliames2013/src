89. Gray Code  QuestionEditorial Solution  My Submissions
Total Accepted: 67660 Total Submissions: 179246 Difficulty: Medium
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

Hide Company Tags Amazon
Show Tags

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

