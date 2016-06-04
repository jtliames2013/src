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
    int findPeakElement(vector<int>& nums) {
    	int n=nums.size();
    	if (n==0) return 0;

    	int l=0, r=n-1;
    	int m=0;
    	while (r >= l) {
    		m=l+(r-l)/2;
    		if ((m-1<0 || nums[m-1]<nums[m]) &&
    			(m+1>=n || nums[m+1]<nums[m])) {
    			return m;
    		} else if (m-1>=0 && nums[m-1]>nums[m]) {
    			r=m-1;
    		} else if (m+1<n && nums[m+1]>nums[m]) {
    			l=m+1;
    		}
    	}

    	return m;
    }
};

int main()
{
	return 0;
}

