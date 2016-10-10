46. Permutations  
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Hide Company Tags LinkedIn Microsoft
Hide Tags Backtracking
Hide Similar Problems (M) Next Permutation (M) Permutations II (M) Permutation Sequence (M) Combinations

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

1. swap and move one number at a time
class Solution {
public:
    void getPerm(vector<vector<int>>& res, vector<int>& nums, int start) {
        if (start==nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i=start; i<nums.size(); i++) {
            swap(nums[start], nums[i]);
            getPerm(res, nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if (n==0) return res;
        getPerm(res, nums, 0);
        
        return res;
    }
};

2. Use additional array to record the number selected.
class Solution {
public:
	void getPermute(vector<vector<int> >& res, vector<int>& nums, vector<int>& solution, vector<bool>& selected) {
		if (solution.size()==nums.size()) {
			res.push_back(solution);
			return;
		}

		for (int i=0; i<nums.size(); i++) {
			if (selected[i]==false) {
				solution.push_back(nums[i]);
				selected[i]=true;
				getPermute(res, nums, solution, selected);
				solution.pop_back();
				selected[i]=false;
			}
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int> > res;
    	std::sort(nums.begin(), nums.end());
    	vector<int> solution;
    	vector<bool> selected(nums.size(), false);
    	getPermute(res, nums, solution, selected);
    	return res;
    }
};


int main()
{
	return 0;
}

