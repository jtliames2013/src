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
    int findKthLargest(vector<int>& nums, int k) {
    	if (nums.size()==0) return 0;
    	int i = rand()%nums.size();
    	int pivot = nums[i];
    	vector<int> n1, n2;

    	for (int i=0; i<nums.size(); i++) {
    		if (nums[i] > pivot) {
    			n1.push_back(nums[i]);
    		} else if (nums[i] < pivot) {
    			n2.push_back(nums[i]);
    		}
    	}

		if (k <= n1.size()) {
			return findKthLargest(n1, k);
		}
		if (k > nums.size()-n2.size()) {
			return findKthLargest(n2, k-(nums.size()-n2.size()));
		}

		return pivot;
    }
};

int main()
{
	return 0;
}


