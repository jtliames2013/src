15. 3Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 134780 Total Submissions: 685476 Difficulty: Medium
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

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
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int> > res;
    	if (nums.size()==0) return res;
    	int start, end;
    	sort(nums.begin(), nums.end());
    	for (int i=0; i<nums.size()-1; i++) {
    		if (i==0 || nums[i]!=nums[i-1]) {
				start=i+1;
				end=nums.size()-1;
				while (start<end) {
					if (nums[i]+nums[start]+nums[end]==0) {
						if ((start==i+1 || nums[start]!=nums[start-1]) &&
							(end==nums.size()-1 || nums[end]!=nums[end+1]))
						{
							vector<int> v;
							v.push_back(nums[i]);
							v.push_back(nums[start]);
							v.push_back(nums[end]);
							res.push_back(v);
						}
						start++;
						end--;
					} else if (nums[i]+nums[start]+nums[end]>0) {
						end--;
					} else {
						start++;
					}
				}
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}


