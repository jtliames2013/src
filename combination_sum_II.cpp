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
	void getCombinationSum2(vector<vector<int> >& res, vector<int>& candidates, int index, vector<int>& curr, int target)
	{
		if (target==0) {
			res.push_back(curr);
			return;
		} else if (target<0) {
			return;
		}

		for (int i=index; i<candidates.size(); i++) {
			if (i>index && candidates[i]==candidates[i-1]) continue;
			curr.push_back(candidates[i]);
			getCombinationSum2(res, candidates, i+1, curr, target-candidates[i]);
			curr.pop_back();
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	vector<vector<int> > res;
    	vector<int> curr;

    	std::sort(candidates.begin(), candidates.end());
    	getCombinationSum2(res, candidates, 0, curr, target);

    	return res;
    }
};

int main()
{
	return 0;
}


