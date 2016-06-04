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
	int roblinear(vector<int>& nums, int start, int end) {
		int odd=0, even=0;
		for (int i=start; i<=end; i++) {
			if (i%2==1) {
				odd=max(even, odd+nums[i]);
			} else {
				even=max(odd, even+nums[i]);
			}
		}

		return max(odd, even);
	}

    int rob(vector<int>& nums) {
    	if (nums.size()==0) return 0;
    	else if (nums.size()==1) return nums[0];

    	return max(roblinear(nums, 0, nums.size()-2), roblinear(nums, 1, nums.size()-1));
    }
};

int main()
{
	return 0;
}


