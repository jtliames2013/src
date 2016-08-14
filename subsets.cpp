78. Subsets  
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Hide Company Tags Amazon Uber Facebook
Hide Tags Array Backtracking Bit Manipulation
Hide Similar Problems (M) Generalized Abbreviation

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
	void getSubsets(vector<vector<int>>& res, vector<int>& nums, vector<int>& v, int index) {
		res.push_back(v);

		for (int i=index; i<nums.size(); i++) {
			v.push_back(nums[i]);
			getSubsets(res, nums, v, i+1);
			v.pop_back();
		}
	}

    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int> > res;
    	vector<int> v;

    	std::sort(nums.begin(), nums.end());
    	getSubsets(res, nums, v, 0);

    	return res;
    }
};

2. No need to sort
class Solution {
public:
    void getSet(vector<vector<int>>& res, vector<int>& output, vector<int>& nums, int start) {
        res.push_back(output);
        
        for (int i=start; i<nums.size(); i++) {
            output.push_back(nums[i]);
            getSet(res, output, nums, i+1);
            output.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        getSet(res, output, nums, 0);
        
        return res;
    }
};

int main()
{
	return 0;
}


