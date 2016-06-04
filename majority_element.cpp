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
    int majorityElement(vector<int>& nums) {
    	map<int, int> counts;
    	int size=nums.size();
    	for (int i=0; i<nums.size(); i++) {
    		auto it=counts.find(nums[i]);
    		if (it==counts.end()) {
    			counts.insert(make_pair(nums[i], 1));
    		} else {
    			(*it).second++;
    		}
    	}

    	for (auto it=counts.begin(); it!=counts.end(); it++) {
    		if ((*it).second > size/2) return (*it).first;
    	}

    	return 0;
    }
};

int main()
{
	return 0;
}

