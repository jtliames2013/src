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
	void kSum(vector<vector<int> >& res, vector<int>& sum, vector<int>& nums, int start, int k, int target) {
		if (k==0) return;
		else if (k==1) {
			for (int i=start; i<nums.size(); i++) {
				if (nums[i]==target) {
					if (i==start || nums[i]!=nums[i-1]) {
						sum.push_back(nums[i]);
						res.push_back(sum);
						sum.pop_back();
					}
				}
			}
		}
		else if (k==2) {
			int l=start, r=nums.size()-1;
			while (l<r) {
				if (nums[l]+nums[r]==target) {
					if ((l==start || nums[l]!=nums[l-1]) &&
						(r==nums.size()-1 || nums[r]!=nums[r]+1)) {
						sum.push_back(nums[l]);
						sum.push_back(nums[r]);
						res.push_back(sum);
						sum.pop_back();
						sum.pop_back();
					}
					l++;
					r--;
				} else if (nums[l]+nums[r]>target) {
						r--;
				} else {
					l++;
				}
			}
		} else {
			for (int i=start; i<nums.size()-k+1; i++) {
				if (i==start || nums[i]!=nums[i-1]) {
					sum.push_back(nums[i]);
					kSum(res, sum, nums, i+1, k-1, target-nums[i]);
					sum.pop_back();
				}
			}
		}

	}

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int> > res;
    	if (nums.size() < 4) return res;
    	sort(nums.begin(), nums.end());
    	vector<int> sum;
  		kSum(res, sum, nums, 0, 4, target);

    	return res;
    }
};

int main()
{
	return 0;
}


