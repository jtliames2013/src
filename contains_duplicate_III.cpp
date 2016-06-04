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
	long long abs(long long a, long long b) {
		return a>b? a-b : b-a;
	}

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	map<int, int> m;
    	for (int i=0; i<nums.size(); i++) {
    		if (t==0) {
    			auto res=m.find(nums[i]);
    			if (res!=m.end()) {
    				if (i-(*res).second<=k) return true;
    			}
    			m[nums[i]]=i;
    		} else {
    			auto res=m.find(nums[i]/t);
    			if (res!=m.end()) {
					if (abs(nums[i], nums[(*res).second])<=t && i-(*res).second<=k) return true;
				}

    			res=m.find(nums[i]/t-1);
    			if (res!=m.end()) {
    				if (abs(nums[i], nums[(*res).second])<=t && i-(*res).second<=k) return true;
    			}

    			res=m.find(nums[i]/t+1);
    			if (res!=m.end()) {
    				if (abs(nums[i], nums[(*res).second])<=t && i-(*res).second<=k) return true;
    			}

    			m[nums[i]/t]=i;
    		}
    	}

    	return false;
    }
};

int main()
{
	return 0;
}

