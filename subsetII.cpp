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
	void getSubsets(vector<int>& nums, vector<vector<int> >& result, vector<int>& subset, unsigned int index)
	{
		if (index >= nums.size()) return;

		for (unsigned int i=index; i<nums.size(); i++)
		{
			if (i==index || nums[i] != nums[i-1])
			{
				subset.push_back(nums[i]);
				result.push_back(subset);
				getSubsets(nums, result, subset, i+1);
				subset.pop_back();
			}
		}
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	vector<vector<int> > result;
    	vector<int> subset;
    	std::sort(nums.begin(), nums.end());
    	result.push_back(subset);
    	getSubsets(nums, result, subset, 0);

    	return result;
    }
};

int main()
{
	return 0;
}

