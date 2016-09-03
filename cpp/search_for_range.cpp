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
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> res;
    	int l=0;
    	int r=nums.size()-1;
    	int m;
    	int start=-1, end=-1;
    	bool found=false;

    	while (l<=r) {
    		m=(l+r)/2;

    		if (nums[m]==target) {
    			found=true;
    			break;
    		} else if (nums[m]<target) {
    			l=m+1;
    		} else {
    			r=m-1;
    		}
    	}

    	if (found) {
    		start=end=m;
    		while (start >=0 && nums[start]==target) {
    			start--;
    		}
    		start++;
    		while(end<nums.size() && nums[end]==target) {
    			end++;
    		}
    		end--;
    	}

    	res.push_back(start);
    	res.push_back(end);
    	return res;
    }
};

int main()
{
	return 0;
}


