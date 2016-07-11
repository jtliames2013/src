47. Permutations II  
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
Hide Company Tags LinkedIn Microsoft
Hide Tags Backtracking
Hide Similar Problems (M) Next Permutation (M) Permutations (M) Palindrome Permutation II

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

NOTE: [0,1,0,0,9], can't use swap as in I because the order will be changed.
class Solution {
public:
	void getPermuteUnique(vector<vector<int> >& res, vector<int>& nums, vector<int>& solution, vector<bool>& selected) {
		if (solution.size()==nums.size()) {
			res.push_back(solution);
			return;
		}

		for (int i=0; i<nums.size(); i++) {
			if (selected[i]==false && (i==0 || selected[i-1]==true || nums[i]!=nums[i-1])) {
				solution.push_back(nums[i]);
				selected[i]=true;
				getPermuteUnique(res, nums, solution, selected);
				solution.pop_back();
				selected[i]=false;
			}
		}
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int> > res;
    	std::sort(nums.begin(), nums.end());
    	vector<int> solution;
    	vector<bool> selected(nums.size(), false);

    	getPermuteUnique(res, nums, solution, selected);

    	return res;
    }
};

int main()
{
	return 0;
}


